#############
def main():
	err, res = find('in.txt')
	if err==0:
		print("answer", res)
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
	res, maximum, pred = None, None, None
	try:
		with open(fn, 'r') as f:
			for word in [s for s1 in f for s2 in s1.split('\n') for s3 in s2.split('\t') for s4 in s3.split(',') for s in s4.split(' ') if s!='']:
				try:
					x=int(word)
					if pred==None:
						pred=x
						temp=x
						prevsum=x
						maximum=x
					else:
						if x!=None:
							temp=prevsum+x
							if (temp-prevsum)>=maximum:
								maximum=temp-prevsum
							if temp>=maximum:
								maximum=temp
							if (x>0)and(prevsum<0)and(pred<0):
								temp=x
							prevsum=temp
							pred=x
					res=maximum
				except ValueError:
					return 2, 0
		if res==None:
			return 3, 0
		else:
			return 0, res
	except FileNotFoundError:
		return 1, 0
###############
main()
