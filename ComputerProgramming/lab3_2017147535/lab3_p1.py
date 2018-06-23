a = int(input('Enter USB size (GB): '))

import math

usb = a * 1000000000

size = 800 * 600

gif = usb // (size * 1 / 5)
jpeg = usb // (size * 3 / 25)
png = usb // (size * 3 / 8)
tiff = usb // (size * 6 / 1)


print('{0:5d}'.format(math.floor(gif)), ' images in GIF format can be stored')
print('{0:5d}'.format(math.floor(jpeg)), ' images in JPEG format can be stored')
print('{0:5d}'.format(math.floor(png)), ' images in PNG format can be stored')
print('{0:5d}'.format(math.floor(tiff)), ' images in TIFF format can be stored')
