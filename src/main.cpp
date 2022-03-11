#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

int main(int argc, const char** argv)
{
    cv::VideoCapture video_capture(0);
    if(!video_capture.isOpened())
    {
        return -1;
    }

    auto exposure{video_capture.get(cv::CAP_PROP_EXPOSURE)};

    std::cout << "Default exposure: " << exposure << std::endl;

    if(argc > 1)
    {
        exposure = std::stod(argv[1]);
    }

    video_capture.set(cv::CAP_PROP_EXPOSURE, exposure);

    std::cout << "New exposure: " << exposure << std::endl;

    return 0;
}
