#pragma once

#include <string>
#include <dshow.h>
#include <vector>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <exception>

#pragma comment(lib, "strmiids") //to get CLSIDs
#pragma comment(lib, "oleaut32") //to get variant routines
#pragma comment(lib, "ole32") //to get CoCreateInstance etc

#include <string>
#include <vector>

class Video_capture_devices
{
    std::vector<std::wstring> m_list;

public:
    Video_capture_devices();
    std::vector<std::wstring> get_list();

private:
    HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum);
    void DisplayDeviceInformation(IEnumMoniker *pEnum);
};
