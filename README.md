# StreamPeer

Low-latency, peer-to-peer live video streaming in C++ using POSIX sockets, OpenCV, and multithreading.

## How It Works

A webcam frame is captured using OpenCV, encodes them using H.264 through FFmpeg, and transmits the compressed frames data directly to another peer over TCP connection using POSIX sockets. The receiver decodes the incoming H.264 stream and displays the reconstructed frames. No WebRTC, cloud infrastructure, or browser is involved.

## Tech

C++17, OpenCV, POSIX sockets


## Documentation

- [OpenCV Notes](docs/opencv.md)