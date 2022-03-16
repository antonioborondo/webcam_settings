#ifndef WEBCAM_SETTINGS_H
#define WEBCAM_SETTINGS_H

#include <QMainWindow>
#include <string>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class webcam_settings; }
QT_END_NAMESPACE

class webcam_settings : public QMainWindow
{
    Q_OBJECT

    std::vector<std::wstring> m_list_devices;

public:
    webcam_settings(const std::vector<std::wstring> &list_devices, QWidget *parent = nullptr);
    //webcam_settings(QWidget *parent = nullptr);
    ~webcam_settings();

private slots:
    void on_m_change_button_clicked();

private:
    Ui::webcam_settings *ui;
};
#endif // WEBCAM_SETTINGS_H
