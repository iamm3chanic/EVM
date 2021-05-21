import random
from PIL import Image, ImageDraw  
 
image = Image.open("1.bmp") 
image2 = Image.open("2.bmp") 
draw = ImageDraw.Draw(image)  
width = image.size[0]  
height = image.size[1]  
width2 = image2.size[0]  
height2 = image2.size[1]  
w=min(width, width2)
h=min(height, height2)
pix = image.load() 
pix2 = image2.load() 

for i in range(w):
	for j in range(h):
	    a = pix[i, j][0]
	    b = pix[i, j][1]
	    c = pix[i, j][2]
	    a1 = pix2[i, j][0]
	    b1 = pix2[i, j][1]
	    c1 = pix2[i, j][2]
	    if a1==0 and b1==0 and c1==0:
	        draw.point((i, j), (a1, b1, c1))
	    else:
		     draw.point((i, j), (a, b, c))
image.save("ans.bmp", "BMP")
del draw
