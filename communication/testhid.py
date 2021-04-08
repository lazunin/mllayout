import hid
import sys
import time

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

# Have to specify the path, because there are several "usage pages" and
# if we choose wrong one we get access denied error
with hid.Device(vendor_id, product_id, path = path) as device:
	codes = [b'\0\1', b'\0\2']
	for i in range(10):
		device.write(codes[i % 2])
		time.sleep(0.5)

