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

vendor_id  = 0x3297  # Found in config.h for the keyboard's main directory
product_id = 0x1969  # (one level above "keymaps")

usage_page = 0xFF60  # The defaults, can be redefined in the same config.h
usage      = 0x61
path       = None    # Found with the code below

for d in hid.enumerate(vendor_id, product_id):
	if d["usage_page"] == usage_page and d["usage"] == usage:
		path = d["path"]

if path is None:
	print("Couldn't connect")
	sys.exit(0)

# English, Russian, Japanese (http://atpad.sourceforge.net/languages-ids.txt)
lids = {0x409: b'\0\1', 0x419: b'\0\2', 0x411: b'\0\3'}
LID = None
while True:
	lid = get_active_language()
	if (lid != LID) and (lid in lids.keys()):
		LID = lid
		#print(lid)
		with hid.Device(vendor_id, product_id, path = path) as device:
			device.write(lids[lid])
	time.sleep(0.5)