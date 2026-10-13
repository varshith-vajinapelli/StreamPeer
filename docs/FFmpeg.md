## References

1. [ffmpeg-libav-tutorial](https://github.com/leandromoreira/ffmpeg-libav-tutorial)
   Chapter 0 & 3
2. [encode_video.c](https://ffmpeg.org/doxygen/trunk/encode_video_8c-example.html)
3. [libavcodec API](https://ffmpeg.org/doxygen/trunk/group__libavc.html)
4. [libswscale (BGR → YUV420P)](https://ffmpeg.org/doxygen/trunk/group__libsws.html)

## FFmpeg-libav-tutorial

video is simply frames running at a certain rate, this is the what it gives the illusion the more fast you run it the smoother it comes out to be!

## Encoder

![alt text](image.png)

- Why do we need encoder & decoder?

look into the image above simply a raw frame if you try to send directly over the interet (40 seconds at 30fps) it will be around 7.2GB! That's terrible worse! So that's why encoder is needed to reduce the size massively!
