import wx, wx.aui
import codecs
import math

#default_font, default_color = wx.Font(10, wx.MODERN, wx.NORMAL, wx.FONTWEIGHT_NORMAL, False, "Fira Code"), wx.Colour(0,   0,   0)
#held_font   , held_color    = wx.Font( 8, wx.MODERN, wx.NORMAL, wx.FONTWEIGHT_NORMAL, False, "Fira Code"), wx.Colour(30, 40, 130)

default_font, default_color, held_font, held_color = [None]*4

def read_layout(fname):
	left_half = []
	right_half = []
	try:
		with codecs.open(fname, "r", encoding = "utf-8") as f:
			for i, line in enumerate(f):
				#if i > 6: break
				left, right = line.split("\t", 1)
				left = left.strip()
				right = right.strip()
				
				left_half.append(left.split())
				right_half.append(right.split())
	except:
		left_half = [[None]*7]*7
		right_half = [[None]*7]*7
		
	return left_half, right_half

class KeyboardLayout:
	def read(self, folder):
		self.nleft, self.nright = read_layout(f"{folder}/layout.normal.txt")
		self.sleft, self.sright = read_layout(f"{folder}/layout.shifted.txt")
		self.hleft, self.hright = read_layout(f"{folder}/layout.held.txt")

class Key:
	def __init__(self, pos, normal = None, shifted = None, held = None, is_tall = False, is_tri = False):
		self.pos     = pos
		self.normal  = normal
		self.shifted = shifted
		self.held    = held
		
		self.w = 50
		self.h = 75 if is_tall else 50
		self.rr = 8
		self.rect = wx.Rect(0, 0, self.w, self.h)
		self.rect.SetPosition(pos)
		
		self.tnx, self.tny = self.pos[0] + 20, self.pos[1] + 25
		if len(self.normal) > 2: self.tnx = self.pos[0] + 5
		self.is_tri = is_tri
		if is_tri:
			self.w = 105
			self.h = 60
			self.tnx = self.pos[0] + 35
		
		self.tsx = self.tnx + 10
		self.tsy = self.tny - 15
		
		self.thx = self.pos[0] + 5
		self.thy = self.pos[1] + self.h - 12
	
	def draw(self, context):
		if self.is_tri:
			shape = [	[self.pos[0], self.pos[1] + self.h],
						[self.pos[0], self.pos[1] + self.h//2],
						[self.pos[0] + self.w//2, self.pos[1]],
						[self.pos[0] + self.w, self.pos[1] + self.h//2],
						[self.pos[0] + self.w, self.pos[1] + self.h],
						]
			context.DrawLines(shape)
		else:
			context.DrawRoundedRectangle(self.pos[0], self.pos[1], self.w, self.h, self.rr)
		if self.normal and self.normal != "None":
			context.DrawText(self.normal, self.tnx, self.tny)
		
		if self.shifted and (self.shifted != self.normal):
			context.DrawText(self.shifted, self.tsx, self.tsy)
		
		if self.held and (self.held != self.normal) and (self.held != self.shifted):
			#context.SetFont(wx.Font(8, wx.MODERN, wx.NORMAL, wx.FONTWEIGHT_NORMAL, False), wx.Colour(30, 40, 130))
			context.SetFont(held_font, held_color)
			context.DrawText(self.held, self.thx, self.thy)
			#context.SetFont(wx.Font(10, wx.MODERN, wx.NORMAL, wx.FONTWEIGHT_NORMAL, False), wx.Colour(0, 0, 0))
			context.SetFont(default_font, default_color)

class KeyPanelBig:
	def __init__(self, ltr = True, normal = None, shifted = None, held = None):
		self.keys = []
		self.tops = [20, 20, 10, 0, 10, 20, 20]
		left = 10
		top = 10
		sz =  50
		pad = 5
		nkeys = 7
		for i in range(5):
			if i > 2: nkeys -= 1
			tops_ = self.tops[:nkeys]
			for nk, t in enumerate(tops_):
				
				left_ = left if ltr else 900 - left
				ksym = nk if ltr else -nk - 1
				self.keys.append(Key((left_, t + top), normal = normal[i][ksym], shifted = shifted[i][ksym], held = held[i][ksym]))
								
				left += sz + pad
			left = 10
			top += sz + pad
	
	def draw(self, context):
		for k in self.keys:
			k.draw(context)
	
class KeyPanelSmall:
	def __init__(self, ltr = True, normal = None, shifted = None, held = None):
		self.keys = []
		self.ltr = ltr
		left = 0
		top = 0
		sz =  50
		pad = 5
		
		if self.ltr:
			self.keys.append(Key((left, top), normal = normal[5][0], shifted = shifted[5][0], held = held[5][0], is_tall = True, is_tri = True))
		else:
			self.keys.append(Key((left + 55, top), normal = normal[5][0], shifted = shifted[5][0], held = held[5][0], is_tall = True, is_tri = True))
		top += self.keys[-1].h + pad
		for i in range(3):
			self.keys.append(Key((left, top), normal = normal[6][i], shifted = shifted[6][i], held = held[6][i], is_tall = True))
			left += sz + pad
	
	def draw(self, context):
		if self.ltr:
			dx, dy, angle = 420, 0, math.pi / 6.0
		else:
			dx, dy, angle = 240, 475, -math.pi / 6.0
		for k in self.keys:
			context.Rotate(angle)
			context.Translate(dx, dy)
			k.draw(context)
			context.Translate(-dx, -dy)
			context.Rotate(-angle)

	
class TestPanel(wx.Panel):
	def __init__(self, parent, kbd):
		wx.Panel.__init__(self, parent, -1)
		self.Bind(wx.EVT_PAINT, self.OnPaint)		

		ly = KeyboardLayout()
		ly.read(kbd)
		
		self.left_panel_big = KeyPanelBig(normal = ly.nleft, shifted = ly.sleft, held = ly.hleft)
		self.left_panel_small = KeyPanelSmall(normal = ly.nleft, shifted = ly.sleft, held = ly.hleft)
		
		self.right_panel_big = KeyPanelBig(ltr = False, normal = ly.nright, shifted = ly.sright, held = ly.hright)
		self.right_panel_small = KeyPanelSmall(normal = ly.nright, shifted = ly.sright, held = ly.hright, ltr = False)
		
		
	def OnPaint(self, evt):
		pdc = wx.PaintDC(self)
		try:
			dc = wx.GraphicsContext.Create(pdc)
		except:
			dc = pdc
		
		rgb = (200, 200, 200)
		dc.SetPen(wx.Pen(wx.Colour(*rgb, wx.ALPHA_OPAQUE)))
		dc.SetBrush(wx.Brush(wx.Colour(*rgb, 128)))
		#dc.SetFont(wx.Font(10, wx.MODERN, wx.NORMAL, wx.FONTWEIGHT_NORMAL, False), wx.Colour(0, 0, 0))
		dc.SetFont(default_font, default_color)

		self.left_panel_big.draw(dc)
		self.left_panel_small.draw(dc)
		
		self.right_panel_big.draw(dc)
		self.right_panel_small.draw(dc)


class MainWindow(wx.Frame):
	def __init__(self, parent, id, title):
		wx.Frame.__init__(self, parent, wx.ID_ANY, title, style=wx.DEFAULT_FRAME_STYLE|wx.NO_FULL_REPAINT_ON_RESIZE)
		
		#self.control = TestPanel(self, "en")
		#self.control.Bind(wx.EVT_TEXT_PASTE, self.OnPaste)
		
		self.control = wx.aui.AuiNotebook(self)
		for s in ["en", "ru", "default_layer1"]:
			self.control.AddPage(TestPanel(self.control, s), s)
		
		self.windowSizer = wx.BoxSizer()
		self.windowSizer.Add(self.control, 1, wx.ALL|wx.EXPAND)
		
		#self.SetSizerAndFit(self.windowSizer)
		self.SetSizer(self.windowSizer)
		self.SetSize(wx.Size((970, 485)))

app = wx.App()

default_font, default_color = wx.Font(10, wx.MODERN, wx.NORMAL, wx.FONTWEIGHT_NORMAL, False, "Fira Code"), wx.Colour(0,   0,   0)
held_font   , held_color    = wx.Font( 8, wx.MODERN, wx.NORMAL, wx.FONTWEIGHT_NORMAL, False, "Fira Code"), wx.Colour(30, 40, 130)

frame = MainWindow(None, -1, "Window")
frame.Show(1)
app.MainLoop()