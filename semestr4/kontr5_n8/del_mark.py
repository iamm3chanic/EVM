from PIL import Image, ImageDraw, ImageFont
import numpy as np

def Water(a):
    return a[0] > 175 and a[0] < 255 and a[1] > 175 and a[1] < 255 and a[2] > 175 and a[2] < 255 and a[3]>60 and a[3]<80
	
def recurse(px,area,i,j,x,y):
    brush=1 #(x*y)//(10000)
    if (i,j) not in area:
        if Water(px[i,j]):
            area[i,j]=px[i,j]
            for i1 in range(i-brush,i+brush):
                for j1 in range(j-brush,j+brush):
                    if i1>0 and j1>0 and i1<x and j1<y:
                        recurse(px,area,i1,j1,x,y)

def middle(img):
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            a,b,c,d = img[i, j]
    return a,b,c,d
        
def select_pixel2(r,g,b,a):
    if r > 175 and r < 255 and g > 175 and g < 255 and b > 175 and b < 255 and a>60:
        return True
    else:
        return False
        
def handle(imgs):
    print("deleting mark...")
    a,b,c,d = middle(imgs)
    for  i in range(imgs.shape[0]-5):
        for j in range(imgs.shape[1]-5):
            if select_pixel2(imgs[i][j][0],imgs[i][j][1],imgs[i][j][2],imgs[i][j][3]):
                #print(imgs[i][j])
                #imgs[i][j][0] ,  imgs[i][j][1] , imgs[i][j][2] = to_border(imgs,i,j)
                imgs[i][j][0] ,  imgs[i][j][1] , imgs[i][j][2] , imgs[i][j][3] = a,b,c,d
                
    return imgs

def save_mark(imgs):
    print("saving mark...")
    im2=Image.new("RGBA", (imgs.shape[1], imgs.shape[0]), (255, 255, 255, -100))
    im2 = np.array(im2)
    for i in range(imgs.shape[0]):
        for j in range(imgs.shape[1]):
            if select_pixel2(imgs[i][j][0],imgs[i][j][1],imgs[i][j][2],imgs[i][j][3]):
                #print(imgs[i][j])
                im2[i][j]= imgs[i][j]
    im = Image.fromarray(np.uint8(im2))
    im.save('mark.bmp')

def main_areas():
    im=Image.open("pic_mark").convert("RGBA")
    x,y=im.size
    px=im.load()
    im2=Image.new("RGBA", (x, y), (0, 0, 0, 0))
    px2=im2.load()
    areas={}
    count=0
    for i in range(x):
        for j in range(y):
            px2[i,j]=px[i,j]
            flag=False
            for k in range(count):
                if (i,j) in areas[k]:
                    flag=True
            if flag==True:
                continue
            else:
                if Water(px[i,j]):
                    tmp={}
                    recurse(px,tmp,i,j,x,y)
                    areas[count]=tmp
                    count=count+1

    for tmp in areas.keys():
        for tmp1 in redareas[tmp].keys():
            brush1=(x*y)//(100000)
            for ii in range(tmp1[0]-brush1,tmp1[0]+brush1):
                for jj in range(tmp1[1]-brush1,tmp1[1]+brush1):
                    if ii>0 and jj>0 and ii<x and jj<y:
                        px2[ii,jj]=px[ii,jj][0]//2,px[ii,jj][1]//2,px[ii,jj][2]//2
    px2=px	
    #print(count)
    im2.save('result.bmp')

def main_fast():
    img = Image.open('pic-mark.bmp').convert("RGBA")
    imgarr1 = np.array(img)
    imgarr2 = np.array(img)
    iii = handle(imgarr1)
    save_mark(imgarr2)
    im = Image.fromarray(np.uint8(iii))
    im.save('result.bmp')

main_fast()
"""img = Image.open('pic-mark.bmp').convert("RGBA")
img = np.array(img)
iii = handle(img)
im = Image.fromarray(np.uint8(iii))
im.save('result.bmp')"""


"""
def little_to_border(img,i,j):
    i1,i2,i3,i4=i,i,i,i
    j1,j2,j3,j4=j,j,j,j
    r=img[i][j][0]
    g=img[i][j][1]
    b=img[i][j][2]
    r0,g0,b0=0,0,0
    k,pix=img[i][j],img[i][j]
    while abs(k[0]-r)<5 and abs(k[1]-g)<5 and abs(k[2]-b)<5 :
        i1+=1
        j1+=1
        if i1 < img.shape[0] and j1 < img.shape[0]:
            k=img[i1][j1]
    if i1 < img.shape[0] and  j1 < img.shape[1]: 
        r0 += img[i1][j1][0] 
        g0 += img[i1][j1][1] 
        b0 += img[i1][j1][2] 
    else:
        r0,g0,b0 = 255,255,255
    return r0,g0,b0


def to_border(img,i,j):
    i1,i2,i3,i4=i,i,i,i
    j1,j2,j3,j4=j,j,j,j
    r=img[i][j][0]
    g=img[i][j][1]
    b=img[i][j][2]
    r0,g0,b0=0,0,0
    k,pix=img[i][j],img[i][j]
    while abs(k[0]-pix[0])<5 and abs(k[1]-pix[1])<5 and abs(k[2]-pix[2])<5 :
        i1+=1
        j1+=1
        if i1 < img.shape[0] and j1 < img.shape[0]:
            k=img[i1][j1]
    while abs(k[0]-img[i][j][0])<5 and abs(k[1]-img[i][j][1])<5 and abs(k[2]-img[i][j][2])<5 :
        i2-=1
        j2-=1
        if i2 > -1 and j2 > -1:
            k=img[i2][j2]
    while abs(k[0]-img[i][j][0])<5 and abs(k[1]-img[i][j][1])<5 and abs(k[2]-img[i][j][2])<5 :
        i3+=1
        j3-=1
        if i3 < img.shape[0] and j3>-1:
            k=img[i3][j3]
    while abs(k[0]-img[i][j][0])<5 and abs(k[1]-img[i][j][1])<5 and abs(k[2]-img[i][j][2])<5 :
        i4-=1
        j4+=1
        if i1>-1 and j4 < img.shape[1]:
            k=img[i4][j4]
#дошли до границы и смотрим области вокруг нее, чтобы заполнить пустоту        
    for count in range(5):
        if i1+count < img.shape[0] and  i2+count < img.shape[0] and j1+count < img.shape[1] and j4+count < img.shape[1] and i2-count > -1 and j2-count > -1 and i4-count > -1 and j3-count > -1 :
            r0 += img[i1+count][j1+count][0] + img[i2-count][j2-count][0] + img[i3+count][j3-count][0] + img[i4-count][j4+count][0]
            g0 += img[i1+count][j1+count][1] + img[i2-count][j2-count][1] + img[i3+count][j3-count][1] + img[i4-count][j4+count][1]
            b0 += img[i1+count][j1+count][2] + img[i2-count][j2-count][2] + img[i3+count][j3-count][2] + img[i4-count][j4+count][2]
        else:
           r0,g0,b0 = 255*5,255*5,255*5
    r0//=5
    g0//=5
    b0//=5
    gone = i1-i,j1-j
    return r0,g0,b0,gone
"""
