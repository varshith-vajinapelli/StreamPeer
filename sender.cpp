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

    capture.open("Screen Recording 2026-02-23 202440.mp4", apiId);

    // check if opened!
    if (!capture.isOpened())
    {
        std::cout << "The camera failed to open" << std::endl;
        return 1;
    }

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

        // TODO: Resize the frame if needed using the resize fucntion?

        cv::imshow("Live", frame);
        int key = cv::waitKey(33);

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