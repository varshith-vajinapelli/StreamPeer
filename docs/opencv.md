cv:mat is an matrix and it's a core part of the open cv
opencv 2.0 brought the c++ and mainly the cv::mat is an automatic memeory managemtn class itself
so it stores the image pixels and the meta data information for this!

and this stores typically one frame not the whole video! and that the reason there are benifts around the mat
one the memory s allocated! the mat is simply here filed with the data and all you need to do it replace the number that should be fast
at least high level is that! you manipualt ehe array change the number around 

You reuse the same mat everytime for every frame simply! overriding the values inside it!
Since you already know how it's expessve to store these images and then when you copy all you get is the new pointer to this
with the meta to youself not the real copy of to get the real copy then you need to explicty .copy() to amke that expensive copy!

Mat sizes matches to camera that filling here!

mat will be simply reused if you pass an existing mat (where the data is intilazied)

So the Mat is a class and simply it contains two parts
1.header(metadata) about the stuff you're holding right now! contains the such as number of rows, columns, data type and pointer to the actual data simply!
2. data buffer: contains the real value typically stored in the heap memeory!

and this means when you pass the mat itself using the ordniary assignmtn it simply copes the header part of the mat, both objects can use the same underlying pixel data here!


When multiple objects points to the same shared heap memeroy if one object goes out of the scopre and the destructor runs adn set the frees the memory right! So that problem comes when other tries it and leads to ud beahipruis to set this opencv uses the refernce couts to track how manya ctive there before it sets the free data actaully!

Some code if needed!

Mat A,B; intialized the stack here for the header and no memory is allocated here at all!
A = imageread() // read the file load it , read the image using the os file i/o decodes the stuff from png or jpeng and have it raw in the bgr
use the  B= A so assignthe contens from the a to b! copy it's simply!
or simply the Mat B = A or Mat B(A)

Region of intrestet;
so if you want t section of the portion frame you can make a copy of this section to you memeory instead of full frame!

// Deep Copy

If you want to make a deep copy here Either use the .clone() or use the object  inbuilt object.copyto(newobject)
Mat f = A.copy();
a.copyto(g);

Image is simply made of pixels and each pixles in the rgb setttings it uses 3 bytes, 1 byte for the each color here! this is logicals for us adn t the enmd of the day it stores in the bytes!

Terminology here so channle is something one part of the pixle that can represent the amount of blue, red or etc!

# OpenCV Notes

## Problem-Solving & Reasoning

Document how I approach problems, why I choose certain solutions, and what I learn along the way.

## Concepts

Important concepts and my understanding of how they work.

## References

1. [OpenCV — Mat: The Basic Image Container](https://docs.opencv.org/5.0/tutorials/core/mat_the_basic_image_container/mat_the_basic_image_container.html)