#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

int main(int argc, const char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: webcam_settings.exe <device> [<exposure>]" << std::endl;

        return -1;
    }

    const auto device{std::stoi(argv[1])};
    cv::VideoCapture video_capture(device);
    if(!video_capture.isOpened())
    {
        std::cout << "Error: Cannot open device " << device << std::endl;

        return -1;
    }

    auto exposure{video_capture.get(cv::CAP_PROP_EXPOSURE)};

    std::cout << "Default exposure: " << exposure << std::endl;

    if(argc > 2)
    {
        exposure = std::stod(argv[2]);
    }

    video_capture.set(cv::CAP_PROP_EXPOSURE, exposure);

    std::cout << "New exposure: " << exposure << std::endl;

    return 0;
}
