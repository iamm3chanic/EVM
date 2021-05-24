#copyright: github.com/SAristeev
import sys
from PIL import Image, ImageDraw
from math import sqrt

def IsRed(a):
	s1=(a[0]+a[1]+a[2])//3
	s2=(a[1]+a[2])//2
	return a[0]>2*(a[1]+a[2]) and int(sqrt(((s2-a[1])**2+(s2-a[2])**2)//2)) < 20 and a[0]>a[1]+a[2] and int(sqrt(((s1-a[0])**2+(s1-a[1])**2+(s1-a[2])**2)//2))> 50
def wave(px,area,i,j,x,y):
	brush=(x*y)//(25000)
	if (i,j) not in area:
		if IsRed(px[i,j]):
			area[i,j]=px[i,j]
			for i1 in range(i-brush,i+brush):
				for j1 in range(j-brush,j+brush):
					if i1>0 and j1>0 and i1<x and j1<y:
						wave(px,area,i1,j1,x,y)


im=Image.open(sys.argv[1])
x,y=im.size
px=im.load()
im2=Image.new("RGB", (x, y), (0, 0, 0))
px2=im2.load()
redareas={}

count=0

for i in range(x):
	for j in range(y):
		px2[i,j]=px[i,j]
		flag=False
		for k in range(count):
			if (i,j) in redareas[k]:
				flag=True
		if flag==True:
			continue
		else:
			if IsRed(px[i,j]):
				tmp={}
				wave(px,tmp,i,j,x,y)
				redareas[count]=tmp
				count=count+1

for tmp in redareas.keys():
	for tmp1 in redareas[tmp].keys():
		brush1=(x*y)//(100000)
		for ii in range(tmp1[0]-brush1,tmp1[0]+brush1):
			for jj in range(tmp1[1]-brush1,tmp1[1]+brush1):
				if ii>0 and jj>0 and ii<x and jj<y:
					v=(px[ii,jj][0]+px[ii,jj][1]+px[ii,jj][2])//3
					px2[ii,jj]=v,v,v
px2=px	
print(count)
im2.save(sys.argv[2])
