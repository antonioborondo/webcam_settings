#ifndef WEBCAM_SETTINGS_H
#define WEBCAM_SETTINGS_H

#include <QMainWindow>
#include <string>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Webcam_settings; }
QT_END_NAMESPACE

class Webcam_settings : public QMainWindow
{
    Q_OBJECT

    std::vector<std::wstring> m_list_devices;

public:
    Webcam_settings(const std::vector<std::wstring> &list_devices, QWidget *parent = nullptr);
    //webcam_settings(QWidget *parent = nullptr);
    ~Webcam_settings();

private slots:
    void on_m_change_button_clicked();

private:
    Ui::Webcam_settings *ui;
};
#endif // WEBCAM_SETTINGS_H
