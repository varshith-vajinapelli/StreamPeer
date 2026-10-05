# StreamPeer

Low-latency, peer-to-peer live video streaming in C++ using POSIX sockets, OpenCV, and multithreading.

## How It Works

A webcam frame is captured with OpenCV, compressed, and sent as a packet over a POSIX socket directly to another peer. The receiver rebuilds the frame and renders it. There is no WebRTC, cloud, or browser involved.

## Tech

C++17, OpenCV, POSIX sockets, std::thread
