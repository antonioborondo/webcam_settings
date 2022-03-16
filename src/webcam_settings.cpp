#include "webcam_settings.h"

#include "ui_webcam_settings.h"
#include "video_capture_devices.h"

#include <opencv2/opencv.hpp>

#include <iostream>

Webcam_settings::Webcam_settings(const std::vector<std::wstring> &video_capture_devices_list, QWidget *parent)
    : m_video_capture_devices_list{video_capture_devices_list}
    , QMainWindow(parent)
    , ui(new Ui::Webcam_settings)
{
    ui->setupUi(this);

    for(const auto video_capture_devices : m_video_capture_devices_list)
    {
        ui->m_devices->addItem(QString::fromStdWString(video_capture_devices));
    }
}

Webcam_settings::~Webcam_settings()
{
    delete ui;
}

void Webcam_settings::on_m_change_button_clicked()
{
    const auto device{ui->m_devices->currentIndex()};
    cv::VideoCapture video_capture(device);

    auto exposure{video_capture.get(cv::CAP_PROP_EXPOSURE)};
    ui->m_default_exposure_value->setText(QString::number(exposure));
    std::cout << "Default exposure: " << exposure << std::endl;

    exposure = ui->m_new_exposure_value->text().toDouble();
    video_capture.set(cv::CAP_PROP_EXPOSURE, exposure);
    std::cout << "New exposure: " << exposure << std::endl;
}
