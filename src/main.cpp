#include <opencv2/opencv.hpp>

#include <string>

int main()
{
    cv::VideoCapture video_capture(0);
    if(!video_capture.isOpened())
    {
        return -1;
    }

    std::string window_name{"Video"};
    cv::namedWindow(window_name, 1);

    for(;;)
    {
        cv::Mat frame;
        video_capture >> frame;

        cv::imshow(window_name, frame);

        if(cv::waitKey(30) >= 0)
        {
            break;
        }
    }

    return 0;
}
