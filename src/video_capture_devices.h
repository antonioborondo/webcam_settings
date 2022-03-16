#pragma once

#include <string>
#include <dshow.h>
#include <vector>
#include <stdint.h>
//#include <iostream>
//#include <fstream>
//#include <exception>

class Video_capture_devices
{
    std::vector<std::wstring> m_list;

public:
    Video_capture_devices();
    const std::vector<std::wstring> get_list();

private:
    HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum);
    void DisplayDeviceInformation(IEnumMoniker *pEnum);
};
