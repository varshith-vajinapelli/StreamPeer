#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>

enum class CameraStatus
{
    Disconnected,
    Connected,
    Recording,
};

struct CameraConfig
{
    int deviceId{0};
    int apiId = cv::CAP_ANY;
    int width{640};
    int height{480};
    int fps{15};
    CameraStatus cameraStatus{CameraStatus::Disconnected};

    // TODO Real Implementation is needed in future!
    void connectCamera()
    {
        cameraStatus = CameraStatus::Connected;
    }

    bool startRecoding()
    {
        if (cameraStatus == CameraStatus::Connected)
        {
            cameraStatus = CameraStatus::Recording;
            return true;
        }

        return false;
    }

    bool setResolution(int width, int height)
    {
        if (width <= 0 || height <= 0)
        {
            return false;
        }

        this->width = width;
        this->height = height;
        return true;
    }
};

void displayCameraInfo(const CameraConfig &config)
{
    std::cout << "Width: " << config.width << '\n';
    std::cout << "Height: " << config.height << '\n';
    std::cout << "FPS: " << config.fps << '\n';
}

int captureVideo(CameraConfig &config)
{
    cv::Mat frame;
    cv::VideoCapture capture;

    capture.open(config.deviceId, config.apiId);

    // change all the direct varible assignment to memebr functions
    config.cameraStatus = CameraStatus::Connected;

    if (!capture.isOpened())
    {
        // change the camera status in the object
        config.cameraStatus = CameraStatus::Disconnected;
        std::cout << "The camera failed to open" << std::endl;
        return 1;
    }

    // sets the property id and value to it!
    // The set may retuns the True if set but it may be incorrect, sue the set to get the values
    // if they are actually set! and using the static public member fucntion of the VideoCapture

    static int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    capture.set(cv::CAP_PROP_FOURCC, codec);

    // sets the frame width & height
    capture.set(cv::CAP_PROP_FRAME_WIDTH, config.width);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, config.height);
    capture.set(cv::CAP_PROP_FPS, config.fps);

    // grab and write
    config.cameraStatus = CameraStatus::Recording;
    while (true)
    {
        // capture the frame from the camera
        capture.read(frame);

        if (frame.empty())
        {
            std::cout << "The frame is blank!" << std::endl;
            break;
        }

        cv::imshow("Live", frame);
        int key = cv::waitKey(1);

        if (key == 'c' || key == 'q')
        {
            std::cout << "Exiting.." << std::endl;
            config.cameraStatus = CameraStatus::Disconnected;
            break;
        }
    }
    return 0;
}

int main()
{
    CameraConfig config{};

    // Defauly Camera Config
    displayCameraInfo(config);

    return captureVideo(config);
}