#Importing Libraries
import random
from PIL import Image, ImageDraw
import sys
#Opening Image & Creating New Text Layer
img = Image.open(sys.argv[1]).convert("RGBA")
draw = ImageDraw.Draw(img)
pix = img.load()

#Getting size
width, height = img.size 

#The bigger the factor - the worse the noise
factor = 50
for i in range(0,width,random.randint(1, 5)):
	for j in range(0,height,random.randint(1, 10)):
		rand = random.randint(-factor, factor)
		a = pix[i, j][0] + rand
		b = pix[i, j][1] + rand
		c = pix[i, j][2] + rand
		if (a < 0):
			a = 0
		if (b < 0):
			b = 0
		if (c < 0):
			c = 0
		if (a > 255):
			a = 255
		if (b > 255):
			b = 255
		if (c > 255):
			c = 255
		draw.point((i, j), (a, b, c))
		
#Saving
img.save('pic-noise.bmp')
del draw
