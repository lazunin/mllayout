import ctypes
import hid, sys
import time

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
		self.LID = None
	
	def update(self):
		lid = get_active_language()
		if (lid != self.LID) and (lid in self.lids.keys()):
			self.LID = lid
			self.ml.write(self.lids[lid])

lc = LayerChanger()
while True:
	lc.update()
	time.sleep(0.5)
