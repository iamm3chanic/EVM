#############
def main():
	err, res, prevsum, pred, sgn,t,ans = find('in.txt')
	if err==0:
		print("answer", res, prevsum, pred,sgn,t,ans)
	elif err==1:
		print("Can't open the file")
	elif err==2:
		print("Bad value")
	elif err==3:
		print("File is empty")
	else:
		print("Error")
###############
def find(fn):
	res, maximum, pred,ans = None, None, None, None
	sgn, t = 0, 0
	try:
		with open(fn, 'r') as f:
			for word in [s for s1 in f for s2 in s1.split('\n') for s3 in s2.split('\t') for s4 in s3.split(',') for s in s4.split(' ') if s!='']:
				try:
					x=int(word)
					if x>0:
						sgn=1
					if x<0:
						sgn=-1
					if x==0:
						ans='no'
					if pred==None:
						pred=sgn
						temp=sgn
						prevsum=sgn
						maximum=sgn
					else:
						if x!=None:
							if(temp<0):
								temp=prevsum+sgn
								if (temp-prevsum)>=maximum:
									maximum=temp-prevsum
								if temp>=maximum:
									maximum=temp
								if (sgn>0)and(prevsum<0)and(pred<0):
									temp=sgn
								prevsum=temp
								pred=sgn
								if(temp<prevsum):
									t+=1
							
							if(temp>0):
								temp=prevsum+sgn
								if (temp-prevsum)>=maximum:
									maximum=temp-prevsum
								if temp>=maximum:
									maximum=temp
								if (sgn>0)and(prevsum<0)and(pred<0):
									temp=sgn
								prevsum=temp
								pred=sgn
								if(temp>prevsum):
									t+=1
						
					res=maximum
				except ValueError:
					return 2, 0, 0, 0
		if res==None:
			return 3, 0, 0, 0
		else:
			return 0, res, prevsum, pred, sgn,t,ans
	except FileNotFoundError:
		return 1, 0, 0, 0
###############
main()
