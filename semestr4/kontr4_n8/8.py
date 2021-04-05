import os
from scipy import misc
from numpy import uint8 as u8
import imageio
im = imageio.imread('pic.bmp')
h=len(im)
w=len(im[0])

print(' width=',w,' height=',h,' size=',w*h*4)
im2=[i for i in range(0,w)]
imageio.imwrite('pic_res.bmp', im)
for ix in range(0,w):
	im2[ix]=[i for i in range(0,h)]
	for iy in range(0,h):
		v=(im[ix][iy][0]+0+im[ix][iy][1]+im[ix][iy][2])//3
		im2[ix][iy]=[v//2,v//1,v//1]
imageio.imwrite('pic2.bmp',im2)
