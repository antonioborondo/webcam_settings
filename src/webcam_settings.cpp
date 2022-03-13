#include "webcam_settings.h"
#include "./ui_webcam_settings.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

webcam_settings::webcam_settings(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::webcam_settings)
{
    ui->setupUi(this);


    const auto device{0};
    cv::VideoCapture video_capture(device);

    auto exposure{video_capture.get(cv::CAP_PROP_EXPOSURE)};

    std::cout << "Default exposure: " << exposure << std::endl;


    video_capture.set(cv::CAP_PROP_EXPOSURE, -6);

    std::cout << "New exposure: " << exposure << std::endl;
}

webcam_settings::~webcam_settings()
{
    delete ui;
}

