#!/usr/bin/env python
# coding: utf-8

# In[301]:


import numpy as np
import sys
import matplotlib.pyplot as plt
from matplotlib.colors import rgb_to_hsv, hsv_to_rgb
from skimage.draw import line_aa
from PIL import Image


# In[302]:


image = Image.open(sys.argv[1])
image = np.array(image, dtype=np.float32) / 255


# In[303]:


hsv = rgb_to_hsv(image)
value = hsv[:, :, 2]


# In[304]:


# Отсуп от краев, чтобы центр лучей был не слишком близко к краям
padding_coef = 0.25

padded_value = value[int(value.shape[0] * padding_coef) : int(value.shape[0] * (1 - padding_coef)), int(value.shape[1] * padding_coef) : int(value.shape[1] * (1 - padding_coef))]
brightest_padded_pixel = np.unravel_index(np.argmax(padded_value, axis=None), padded_value.shape)

brightest_pixel = (
    brightest_padded_pixel[0] + int(value.shape[0] * 0.25),
    brightest_padded_pixel[1] + int(value.shape[1] * 0.25),
)

p = image[brightest_pixel]


# In[305]:


# Длина луча
ray_length_coef = 0.2
# Число лучей
nrays = 10

ray_length = int(value.shape[0] * ray_length_coef)

for phi in np.arange(0, 2 * np.pi, 2 * np.pi / nrays):
    end_rr = int(brightest_pixel[0] + ray_length * np.cos(phi))
    end_cc = int(brightest_pixel[1] + ray_length * np.sin(phi))

    rr, cc, _ = line_aa(brightest_pixel[0], brightest_pixel[1], min(end_rr, value.shape[0] - 1), min(end_cc, value.shape[1] - 1))

    image[rr, cc] = p


# In[307]:


plt.imshow(image)


# In[308]:


image = np.rint(image * 255).astype(np.uint8)
image = Image.fromarray(image)
image.save("out.bmp")


# In[ ]:




