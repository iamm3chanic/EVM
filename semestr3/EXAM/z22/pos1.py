'''Написать программу на языке Python, которая вводит все слова, разделенные пробелами, 
табуляциями и переходами на следующую строчку, из файла http://lectures.stargeo.ru/tO.txt в 
список строк, лексикографически сортирует список стандартной функцией и выводит полученный 
массив в файл ./t0.txt по одной строке в строку файла.'''
#############
def main():
	err, res= find('in.txt')
	if err==0:
		print("answer", res)
		fi = open('example.txt','w')
		try:
			for c in res:
 				fi.write(c)
 				fi.write('\n')
		finally:
 			fi.close()
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
	res=[]
	try:
		with open(fn, 'r') as f:
			for word in [s for s1 in f for s2 in s1.split('\n') for s3 in s2.split('\t') for s4 in s3.split(',') for s in s4.split(' ') if s!='']:
				try:
					x=str(word)
					res.append(x)
					res.sort()
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
