import sys
from PIL import Image, ImageDraw
#открыли изображение
im=Image.open(sys.argv[2])
x,y=im.size
px=im.load()
#получили число пикселей в рамке
n=int(sys.argv[1])
#создали новое изображение
im2=Image.new("RGB", (x+2*n, y+2*n), (0, 0, 0))
px2=im2.load()
for i in range(x+2*n):
	for j in range(y+2*n):
		if i>n and i<x+n and j>n and j<y+n:
			r1,g1,b1=px[i-n,j-n]
			px2[i,j]=r1,g1,b1
		else:
			px2[i,j]=0,0,0
#сохранили с именем, введённым в командной строке
im2.save(sys.argv[3])
