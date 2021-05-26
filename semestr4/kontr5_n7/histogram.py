import numpy as np
import sys
from PIL import Image, ImageDraw

def get_percentile(val, bucket_number): #создаем массив перцентилей
    percentiles=[0.0]
    for i in range(bucket_number - 1):
        percentiles.append(np.percentile(val,(100//bucket_number)*(i+1)))
    return percentiles

def get_percentile_number(value, percentiles): 
    for i in range(len(percentiles)):
        if percentiles[i] > value:
            return i-1
    return len(percentiles)-1

def value_equalization(value, percentiles): #эквализация числа по массиву перцентилей
    idx = get_percentile_number(value, percentiles)
    step = 1/len(percentiles)
    new_value = idx*step
    return new_value

def values_equalization(val, percentiles): #эквализация массива по его массиву перцентилей
    newval=val.copy()
    for i in range(len(val)):
        newval[i]=value_equalization(val[i], percentiles)
    return newval


img = Image.open(sys.argv[1])
draw = ImageDraw.Draw(img)
width = img.size[0]
height = img.size[1]
r = np.zeros((height* width), dtype=float)
g = np.zeros((height* width), dtype=float)
b = np.zeros((height* width), dtype=float)
px = np.array(img) / 255.

r = px[..., 0].reshape((height * width,)) #массив значений красного канала
g = px[..., 1].reshape((height * width,)) #синего
b = px[..., 2].reshape((height * width,)) #зеленого
rr=r.copy()
gg=g.copy()
bb=b.copy()
perr=get_percentile(rr,100) #массив перцентилей для массивов каналов
perg=get_percentile(gg,100)
perb=get_percentile(bb,100)
newr=values_equalization(r, perr) #эквализированные каналы
newg=values_equalization(g, perg)
newb=values_equalization(b, perb)

newrr=np.reshape(newr,(height,width)) #возвращаем массивам былую двумерную форму
newgg=np.reshape(newg,(height,width))
newbb=np.reshape(newb,(height,width))
new_img = np.zeros_like(px)
new_img[..., 0] = newrr
new_img[..., 1] = newgg
new_img[..., 2] = newbb
new_img[..., 3] = px[..., 3] #рисуем картинку с уже эквализированной гистограммой

i = Image.fromarray(np.uint8(new_img * 255))
i.save(sys.argv[2])
