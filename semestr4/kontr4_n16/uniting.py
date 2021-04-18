"""
16. Формат вызова программы должен быть следующим:
./prog InputFile1 InputFile2 OutputFile
Программа должна загрузить изображения из графических файлов
InputFile1 и InputFile2, склеить два введенных изображения по горизон-
тали и вывести получившееся изображение в графический файл OutputFile.
"""
import random
from PIL import Image, ImageDraw  
from sys import argv

script, first, second, third = argv

print ("Этот скрипт называется: ", script)
print ("Соединяем изображения: ", first, " и ", second)
print ("Сохраняем изображение в файл: ", third)
#image = Image.open("losyash.bmp") 
image1 = Image.open(first) 
image2 =  Image.open(second) 
 
width = image1.size[0]  
height = image1.size[1]  
width2 = image2.size[0]  
height2 = image2.size[1]  
w=min(width, width2)
h=min(height, height2)	
im = Image.new("RGBA", (w, height+height2), (0, 0, 0, 0))
draw = ImageDraw.Draw(im) 
pix = image1.load() 
pix2 = image2.load() 

factor=0
factor1=0
		
for i in range(w):
	for j in range(height+height2):
		if j<height:
			a1 = pix[i, j][0]  
			b1 = pix[i, j][1] 
			c1 = pix[i, j][2] 
		else :
			a1 = pix2[i, j-height][0] 
			b1 = pix2[i, j-height][1] 
			c1 = pix2[i, j-height][2] 
		draw.point((i, j), (a1, b1, c1))
im.save(third, "BMP")
del draw
