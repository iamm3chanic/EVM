############### задача 11: номер последнего числа, равного х
def main():
    err, num = find('in.txt')
    if err==0:
        print("answer", num)
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
    val, num = None, None
    try:
        with open(fn, 'r') as f:
            i=0
            for word in [s for s1 in f for s2 in s1.split('\n') for s3 in s2.split('\t') for s4 in s3.split(',') for s in s4.split(' ') if s!='']:
                try:
                    x=int(word)
                    if val==None:
                        val=x
                        num=0
                    else:
                        if x==val:
                            num=i
                    i+=1
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