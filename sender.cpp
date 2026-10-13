#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>

int captureVideo()
{
    cv::Mat frame;
    cv::VideoCapture capture;

    int deviceId = 0;
    int apiId = cv::CAP_ANY;
    unsigned long int totalVideoSize = 0;

    capture.open(deviceId, apiId);

    // check if opened!
    if (!capture.isOpened())
    {
        std::cout << "The camera failed to open" << std::endl;
        return 1;
    }

    // sets the property id and value to it!
    // The set may retuns the True if set but it may be incorrect, sue the set to get the values
    // if they are actually set! and using the static public member fucntion of the VideoCapture

    static int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    capture.set(cv::CAP_PROP_FOURCC, codec);

    // sets the frame width & height
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    capture.set(cv::CAP_PROP_FPS, 15);

    // grab and write
    while (true)
    {
        // capture the frame from the camera
        capture.read(frame);

        if (frame.empty())
        {
            std::cout << "The frame is blank!" << std::endl;
            break;
        }

        // Using size of one pixel bytes * Number of pixels, calcaultes the total frame size in bytes!
        totalVideoSize += frame.total() * frame.elemSize();
        std::cout << "TotalVideoSize: " << totalVideoSize << std::endl;

        cv::imshow("Live", frame);
        int key = cv::waitKey(1);

        if (key == 'c' || key == 'q')
        {
            std::cout << "Exiting.." << std::endl;
            break;
        }
    }
    std::cout << "TotalVideoSize: " << totalVideoSize << std::endl;
    return 0;
}

int main()
{
    int status = captureVideo();

    return status;
}