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
that can represent a color or intensity like alpha!etc!
Channel is stored typically in the 8 bits which is 1 byte so this means a pixel is around the 3 bytes so common types re this

CV_8UC3 =  Bits per channel is 8, bytes per channel is 1 byte, Byte per pixel in (rgb) is 3 bytes!
8 bits for unsigned int
So more bits guves you more prescion

How ever the opencv uses the bgr instead of the rgb!

How to read an image, display an image adn write to an image!

read an image: (using the computer vision namespace) cv::imread , image read
so reading and wringin to iamge is from teh imgcodecs


adn the highgui is for windows to show an image in windows!

before that these are the core part where the headers are located here

<opencv2/core.hpp> contains the basic data types and building blocks of everything
<opencv2/imgcodecs.hpp> handles functiosn to reading and writing to a image!
<opencv2/highgui> contains windows keys and used to show an image in winsows!

as you know eveything is stored in bits on computer, but the files stores the compressed jpeg version not the real raw grids version
so the imread doesi is asks the os for the bytes and it uses the decoder to decode this and build the whole grid array as Mat data type

IMREAD_UNCHANGED: keeps what ever it as
- color jpeg comes out as bgr, grayscale as one challe and png as 4
- imread_color: forces 3 channel bgr no matter what anyfile will force into this
- imread_grascae: forced into the one channek!

jpeg is 3 channels by defauly(color) not 4! an can be 1 grascale
and pbg is defauly 4

and loads everything into the matrix


display an image using the opencv window
write to an image

So Compilation step & Linking Step
Compilation .cpp to object files: So the opencv needs to know the headers. 

"": this simply gives us the or tell the compiler to serach in the same folder!
<>: this tell look inside or looks init's include serach folderand mainly defauly is this
/usr/include

So you need to provide extra -I let the compiler to know to seach one more place
if it's not in this palce you need to get the -I
/usr/include/opencv4 + opencv2/core.hpp

pkg-config is program and when you run this pkg-config --cflags opencv4
looks into it and bring the compiler files

pkg-config --libs opencv4 : this mentions the linker flags here!



# OpenCV Notes

## Problem-Solving & Reasoning

Document how I approach problems, why I choose certain solutions, and what I learn along the way.

## Concepts

Important concepts and my understanding of how they work.

## References

1. [OpenCV — Mat: The Basic Image Container](https://docs.opencv.org/5.0/tutorials/core/mat_the_basic_image_container/mat_the_basic_image_container.html)