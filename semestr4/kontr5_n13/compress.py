import sys
from PIL import Image, ImageDraw
im1=Image.open(sys.argv[1])
x1,y1=im1.size
px1=im1.load()
imout=Image.new("RGB", (x1, y1), (0, 0, 0))
pxout=imout.load()
for i in range(x1):
	for j in range(y1):
		r1,g1,b1=px1[i,j]
		compression=0.9
		n=(1-compression)
		if i<x1//2:
			i1=int(i**n/(x1//2)**(n-1))
			i2=int((i+1)**n/(x1//2)**(n-1))
			for k in range(i1,i2):
				if k<x1//2:
					pxout[k,j]=r1,g1,b1
		else:
			i1=int((x1-i-1)**n/(x1//2)**(n-1))
			i2=int((x1-i)**n/(x1//2)**(n-1))
			for k in range(x1-i2,x1-i1):
				pxout[k,j]=r1,g1,b1

imout.save(sys.argv[2])
