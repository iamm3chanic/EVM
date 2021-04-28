#Importing Libraries
import random
from PIL import Image, ImageDraw, ImageFont

#Opening Image & Creating New Text Layer
img = Image.open('pic.bmp').convert("RGBA")
txt = Image.new('RGBA', img.size, (255,255,255,0))

#Creating Text
text = "lectures.stargeo.ru"
font = ImageFont.truetype("20443.otf", 62)

#Creating Draw Object
d = ImageDraw.Draw(txt)

#Positioning Text
width, height = img.size 
textwidth, textheight = d.textsize(text, font)
x=width/2-textwidth/2
y=height/2-textheight

#Applying Text
print("making mark...")
d.text((x,y), text, fill=(200,200,200,70), font=font)

#Combining Original Image with Text and Saving
watermarked = Image.alpha_composite(img, txt)
watermarked.save('pic-mark.bmp')
