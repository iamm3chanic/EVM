############## задача 7: каких элементов больше: больших предыдущего или меньших предыдущего?
def main():
	err, num = find('in.txt')
	if err==0:
		print("answer ", num)
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
	numhigh, numlow = 0, 0
	num, prev = None, None
	try:
		with open(fn, 'r') as f:
			for word in [s for s1 in f for s2 in s1.split('\n') for s3 in s2.split('\t') for s4 in s3.split(',') for s in s4.split(' ') if s!='']:
				try:
					nexxt=int(word)
					if prev == None:
						prev=nexxt
					else:
						if prev<nexxt:
							numhigh+=1
						elif prev>nexxt:
							numlow+=1
						prev=nexxt
					if numhigh>numlow:
						num='bolshe'
					elif numhigh<numlow:
						num='menshe'
					elif numhigh==numlow:
						num='equal'
				except ValueError:
					return 2, 0
		if num==None:
			return 3, 0
		else:
			return 0, num
	except FileNotFoundError:
		return 1, 0
###############
main()
