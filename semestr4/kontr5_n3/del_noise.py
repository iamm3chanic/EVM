from PIL import Image, ImageDraw, ImageFilter
import multiprocessing
import numpy 
import sys

def lib_edit(im):  
    im2 = im.filter(ImageFilter.MedianFilter(size = 3)) 
    im2.save('result-lib.bmp')

def user_edit(im):
    im = im.convert("RGBA")
    data = numpy.array(im)
    #print(data)
    filter_size = 1
    temp = []
    indexer = filter_size // 2
    data_final = []
    data_final = numpy.zeros((len(data),len(data[0]),4))
    for i in range(len(data)):

        for j in range(len(data[0])):

            for z in range(filter_size):
                if i + z - indexer < 0 or i + z - indexer > len(data) - 1:
                    for c in range(filter_size):
                        temp.append([0,0,0,0])
                else:
                    if j + z - indexer < 0 or j + indexer > len(data[0]) - 1:
                        temp.append([0,0,0,0])
                    else:
                        for k in range(filter_size):
                            temp.append(data[i + z - indexer][j + k - indexer])

            temp.sort()
            data_final[i][j] = temp[len(temp) // 2]
            temp = []
    im2 = Image.fromarray(data_final.astype(numpy.uint8)).convert('RGB')
    im2.save('result-user.bmp')

def user_edit1(im):
    im = im.convert("L")
    data = numpy.array(im)
    filter_size = 1
    temp = []
    indexer = filter_size // 2
    data_final = []
    data_final = numpy.zeros((len(data),len(data[0])))
    for i in range(len(data)):

        for j in range(len(data[0])):

            for z in range(filter_size):
                if i + z - indexer < 0 or i + z - indexer > len(data) - 1:
                    for c in range(filter_size):
                        temp.append(0)
                else:
                    if j + z - indexer < 0 or j + indexer > len(data[0]) - 1:
                        temp.append(0)
                    else:
                        for k in range(filter_size):
                            temp.append(data[i + z - indexer][j + k - indexer])

            temp.sort()
            data_final[i][j] = temp[len(temp) // 2]
            temp = []
    im2 = Image.fromarray(data_final).convert('RGBA')
    im2.save('result-user-black-white.bmp')

def user_edit_par(data):
    #print(data)
    filter_size = 1
    temp = []
    indexer = filter_size // 2
    data_final = []
    data_final = numpy.zeros((len(data),len(data[0]),4))
    for i in range(len(data)):

        for j in range(len(data[0])):

            for z in range(filter_size):
                if i + z - indexer < 0 or i + z - indexer > len(data) - 1:
                    for c in range(filter_size):
                        temp.append([0,0,0,0])
                else:
                    if j + z - indexer < 0 or j + indexer > len(data[0]) - 1:
                        temp.append([0,0,0,0])
                    else:
                        for k in range(filter_size):
                            temp.append(data[i + z - indexer][j + k - indexer])

            temp.sort()
            data_final[i][j] = temp[len(temp) // 2]
            temp = []
    im2 = Image.fromarray(data_final.astype(numpy.uint8)).convert('RGB')
    im2.save('result-user-parall.bmp')

def main():
    im1 = Image.open(sys.argv[1])    
    lib_edit(im1)
    
    im2 = Image.open(sys.argv[1])
    user_edit(im2) 
    
    im3 = Image.open(sys.argv[1])
    user_edit1(im3) 
    
    im4 = Image.open(sys.argv[1])
    im4 = im4.convert("RGBA")
    data = numpy.array(im4)
    pool = multiprocessing.Pool()
    pool.map(user_edit_par, data) 

######### main ##########
main()
