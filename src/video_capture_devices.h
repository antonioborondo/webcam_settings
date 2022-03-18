#pragma once

#include <dshow.h>
#include <stdint.h>
#include <string>
#include <vector>

class Video_capture_devices
{
    std::vector<std::wstring> m_list;

public:
    Video_capture_devices();
    const std::vector<std::wstring> get_list() const;

private:
    HRESULT EnumerateDevices(REFGUID category, IEnumMoniker** ppEnum);
    void DisplayDeviceInformation(IEnumMoniker* pEnum);
};
