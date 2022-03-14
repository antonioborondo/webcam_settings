#include "webcam_settings.h"
#include "./ui_webcam_settings.h"
#include "video_capture_devices.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

webcam_settings::webcam_settings(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::webcam_settings)
{
    ui->setupUi(this);
}

webcam_settings::~webcam_settings()
{
    delete ui;
}


void webcam_settings::on_m_change_button_clicked()
{
    const auto device{ui->m_device_value->text().toInt()};
    cv::VideoCapture video_capture(device);

    auto exposure{video_capture.get(cv::CAP_PROP_EXPOSURE)};
    ui->m_default_exposure_value->setText(QString::number(exposure));
    std::cout << "Default exposure: " << exposure << std::endl;

    exposure = ui->m_new_exposure_value->text().toDouble();
    video_capture.set(cv::CAP_PROP_EXPOSURE, exposure);
    std::cout << "New exposure: " << exposure << std::endl;
}
