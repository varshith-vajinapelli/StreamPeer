#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


int main()
{

    // read an image using the imread functions from the cv namespace!

    cv::Mat img = cv::imread("Screenshot 2026-10-11 162237.png", cv::IMREAD_COLOR);

    if(img.empty()){
        std::cout <<"Couldn't load properly!"<<std::endl;
    }

    cv::imshow("Displayfirst image",img);
    int k = cv::waitKey(0);

    if(k == 's')
    {
        imwrite("Screenshot 2026-10-11 162237.png", img);
    }

    return 0;
}