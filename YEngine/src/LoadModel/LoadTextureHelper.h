#pragma once

#include <wrl.h> 
#include "WICTextureLoader12.h"

using Microsoft::WRL::ComPtr;

void CreateWICTextureFromFile12(_In_ ID3D12Device* device,
    _In_ ID3D12GraphicsCommandList* cmdList,
    _In_z_ const wchar_t* szFileName,
    _Out_ ComPtr<ID3D12Resource>& texture,
    _Out_ ComPtr<ID3D12Resource>& textureUploadHeap
);