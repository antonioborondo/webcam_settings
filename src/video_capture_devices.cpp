#include "video_capture_devices.h"

Video_capture_devices::Video_capture_devices()
{
    HRESULT result{CoInitializeEx(NULL, COINIT_MULTITHREADED)};
    if(SUCCEEDED(result))
    {
        IEnumMoniker* enumerator;
        result = EnumerateDevices(CLSID_VideoInputDeviceCategory, &enumerator);
        if(SUCCEEDED(result))
        {
            DisplayDeviceInformation(enumerator);
            enumerator->Release();
        }

        CoUninitialize();
    }
}

const std::vector<std::wstring> Video_capture_devices::get_list() const
{
    return m_list;
}

HRESULT Video_capture_devices::EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)
{
    // Create the System Device Enumerator.
    ICreateDevEnum *pDevEnum;
    HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
        CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDevEnum));

    if (SUCCEEDED(hr))
    {
        // Create an enumerator for the category.
        hr = pDevEnum->CreateClassEnumerator(category, ppEnum, 0);
        if (hr == S_FALSE)
        {
            hr = VFW_E_NOT_FOUND;  // The category is empty. Treat as an error.
        }
        pDevEnum->Release();
    }
    return hr;
}


void Video_capture_devices::DisplayDeviceInformation(IEnumMoniker *pEnum)
{
    IMoniker *pMoniker = NULL;

    while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
    {
        IPropertyBag *pPropBag;
        HRESULT hr = pMoniker->BindToStorage(0, 0, IID_PPV_ARGS(&pPropBag));
        if (FAILED(hr))
        {
            pMoniker->Release();
            continue;
        }

        VARIANT var;
        VariantInit(&var);

        // Get description or friendly name.
        hr = pPropBag->Read(L"Description", &var, 0);
        if (FAILED(hr))
        {
            hr = pPropBag->Read(L"FriendlyName", &var, 0);
        }
        if (SUCCEEDED(hr))
        {
            m_list.push_back(var.bstrVal);
            VariantClear(&var);
        }

        pPropBag->Release();
        pMoniker->Release();
    }
}
