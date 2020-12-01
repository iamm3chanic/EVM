# 6. Дано множество точек. Найти центр и радиус минимального круга, 
# который содержит все эти точки.
import math
#############
def main():
	err,c = BuildCircle('dots.txt')
	if err==0:
		print("answer", c)
	elif err==1:
		print("Can't open the file")
	elif err==2:
		print("File is empty")
	elif err==3:
		print("Bad value")
	else:
		print("Error!")
###############
def IsInCircle(dx, dy, cx, cy, r):
	"""(X - Xo)^2 +(Y - Yo)^2 <= R^2, Здесь (X, Y) - координаты точки.
           Если неравенство выполняется, то точка принадлежит кругу."""
	if (dx-cx)*(dx-cx) + (dy-cy)*(dy-cy) <= r*r:
		return 1
	else:
		return 0
###############
def FindMax(fn):   
# returning err, dmax, (i1,j1) - numbers of those dots
	i1,j1, maxr = None, None, None
	c=0
	l1=[]
	l2=[]
	xx=[]
	yy=[]
	try:
		with open(fn, 'r') as f:
			for word in [s for s1 in f for s2 in s1.split('\n') for s3 in s2.split('\t') for s4 in s3.split(',') for s in s4.split(' ') if s!='']:
				try:  
					x=(float(word))
					#(x,y)=(int(word),int(word))
					l1.append(x)
					#l2.append(x)
				except ValueError:
					return 2, 0,0,0
					"""for i in l1:
						c=c+1
						if c%2==0:
							del i
					for i in range(len(l2)):
						if i%2==1:
							del l2[i]
					print(l1)
					print(l2)"""
			for k in range (int(len(l1))):
				if k%2==0:
					xx.append(l1[k])
				if k%2==1:
					yy.append(l1[k])
			#print(xx)
			#print(yy)
			maxr=0;
			for i in range (int(len(xx))):
  				for j in range (int(len(xx))):
  					r=math.sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]))
  					#print(r)  		
  					if r>maxr:
  						maxr=r
  						i1=i
  						j1=j
		if maxr==None:
			return 3, 0,0,0
		else:
			return 0, maxr,i1,j1
	except FileNotFoundError:
		return 1, 0,0,0
###############
def BuildCircle(fn):
# returns err & circle - list of 3 float
	c=[]
	l1=[]
	xx=[]
	yy=[]
	try:
		with open(fn, 'r') as f:
			for word in [s for s1 in f for s2 in s1.split('\n') for s3 in s2.split('\t') for s4 in s3.split(',') for s in s4.split(' ') if s!='']:
				try:  
					x=(float(word))
					l1.append(x)
				except ValueError:
					return 2, 0,0,0
			e, dmax,i1,j1 = FindMax(fn)
			for k in range (int(len(l1))):
				if k%2==0:
					xx.append(l1[k])
				if k%2==1:
					yy.append(l1[k])
			if len(xx)==0:
				c=None
			if len(xx)==1:
				#окружность в точке
				c=[0,xx[0],yy[0]]
			if len(xx)==2:
				#окружность по двум точкам
				r=math.sqrt( math.sqr(xx[0]-xx[1]) + math.sqr(yy[0]-yy[1]) );
				c=[r/2,(xx[0]+xx[1])/2, (yy[0]+yy[1])/2]				
			elif len(xx)>2:
				#по длиннейшему диаметру, или строим описанную
				c=[dmax/2, (xx[i1]+xx[j1])/2, (yy[i1]+yy[j1])/2]
				#проверим
				flag=0
				for i in range (len(xx)):
					if IsInCircle(xx[i],yy[i],c[1],c[2],c[0]):
						flag=flag+1
				if flag!=len(xx): 
				#если не прошло по длиннейшему диаметру, то 
					sx,sy,mx=0,0,0;
                                        #найдем координаты центра тяжести множества точек
					for i in range (len(xx)):
						sx=sx+xx[i]; 
						sy=sy+yy[i];
					sx=sx/n;
					sy=sy/n;
					mx=(math.sqr(sx-xx[0]) + math.sqr(sy-yy[0]));
					#найдем наиболее удаленную точку от центра
					for i in range (len(xx)):
						if (math.sqr(sx-xx[i])+math.sqr(sy-yy[i])) > mx : 
							mx = (math.sqr(sx-xx[i])+math.sqr(sy-yy[i]));
					mx=math.sqrt(mx);
					c=[mx, sx, sy]
		if c==None:
			return 2,0
		else:
			return 0,c
	except FileNotFoundError:
		return 1,0
###############
main()


