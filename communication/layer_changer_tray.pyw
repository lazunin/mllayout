import ctypes
import hid, sys
import time

from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *

user32 = ctypes.windll.user32

def get_active_language():
	h_wnd = user32.GetForegroundWindow()
	thread_id = user32.GetWindowThreadProcessId(h_wnd, 0)
	klid = user32.GetKeyboardLayout(thread_id)
	lid = klid & (2**16 - 1)
	return lid

class Moonlander:
	def __init__(self):
		self.vendor_id  = 0x3297  # Found in config.h for the keyboard's main directory
		self.product_id = 0x1969  # (one level above "keymaps")

		self.usage_page = 0xFF60  # The defaults, can be redefined in the same config.h
		self.usage      = 0x61
		self.path       = None    # Found with the code below
		
		for d in hid.enumerate(self.vendor_id, self.product_id):
			if d["usage_page"] == self.usage_page and d["usage"] == self.usage:
				self.path = d["path"]
	
	def write(self, data):
		if self.path is None: return False
		with hid.Device(self.vendor_id, self.product_id, path = self.path) as device:
			data_ = b'\0' + data
			device.write(data_)
		return True

class LayerChanger:
	def __init__(self):
		self.ml = Moonlander()
		# English, Russian, Japanese (http://atpad.sourceforge.net/languages-ids.txt)
		self.lids = {0x409: b'\1', 0x419: b'\2', 0x411: b'\3'}
		self.langs = {0x409: "en", 0x419: "ru", 0x411: "ja"}
		self.LID = None
	
	def get_lang(self):
		if self.LID is None: return None
		return self.langs[self.LID]

	def update(self):
		lid = get_active_language()
		if (lid != self.LID) and (lid in self.lids.keys()):
			self.LID = lid
			self.ml.write(self.lids[lid])

class TrayStuff:
	def __init__(self):

		self.lc = LayerChanger()

		side = 32
		self.draw_rect = QRectF(0, 0, side, side)
		self.pixmap = QPixmap(QSize(side, side))
		self.pixmap.fill(QColor(0, 0, 0, 0))
		
		self.painter = QPainter(self.pixmap)
		
		self.colors = {"en": QColor(0, 0, 255, 255), "ru": QColor(0, 255, 0, 255), "ja": QColor(255, 255, 0, 255)}
		self.tcolors = {"en": QColor(255, 255, 255, 255), "ru": QColor(0, 0, 0, 255), "ja": QColor(0, 0, 0, 255)}
		
		self.tray = QSystemTrayIcon()
		
		self.menu = QMenu()
		
		actions = [("Quit", self.on_quit)]
		self.actions = []
		for title, handler in actions:
			action = QAction(title)
			action.triggered.connect(handler)
			self.menu.addAction(action)
			self.actions.append(action)

		self.tray.setContextMenu(self.menu)
		
		self.timer = QTimer()
		self.timer.timeout.connect(self.set_icon)
		self.timer.start(500)
	

	def on_quit(self):
		self.tray.hide()
		sys.exit(0)
	
	def set_icon(self):
		self.lc.update()
		lang = self.lc.get_lang()
		color = self.colors[lang]
		self.pixmap.fill(QColor(0, 0, 0, 0))

		self.painter.setBrush(QBrush(color))
		self.painter.setPen(QPen(QColor(0, 0, 0, 0)))
		self.painter.drawPie(self.draw_rect, 0, 5760)

		self.painter.setFont(QFont("Tahoma", 15, 9))
		self.painter.setBrush(QBrush(self.tcolors[lang]))
		self.painter.setPen(QPen(self.tcolors[lang]))
		self.painter.drawText(3, 23, lang.upper())
		
		self.icon = QIcon(self.pixmap)
		self.tray.setIcon(self.icon)
		self.tray.setVisible(True)
		self.tray.setToolTip(lang)

app = QApplication([])
app.setQuitOnLastWindowClosed(False)
ts = TrayStuff()
app.exec_()
