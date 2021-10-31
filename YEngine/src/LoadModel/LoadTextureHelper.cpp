#include "pch.h"
#include "WICTextureLoader12.h"

void CreateWICTextureFromFile12(_In_ ID3D12Device* device,
    _In_ ID3D12GraphicsCommandList* cmdList,
    _In_z_ const wchar_t* TextureFileName,
    _Out_ ComPtr<ID3D12Resource>& texture,
    _Out_ ComPtr<ID3D12Resource>& textureUploadHeap
)
{
    std::unique_ptr<uint8_t[]> wicData;
    D3D12_SUBRESOURCE_DATA subresource;
    ThrowIfFailed(DirectX::LoadWICTextureFromFile(device, TextureFileName, texture.ReleaseAndGetAddressOf(), wicData, subresource));

    const UINT64 uploadBufferSize = GetRequiredIntermediateSize(texture.Get(), 0, 1);

    CD3DX12_HEAP_PROPERTIES heapProps(D3D12_HEAP_TYPE_UPLOAD);

    auto desc = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);

    ThrowIfFailed(device->CreateCommittedResource(
        &heapProps, D3D12_HEAP_FLAG_NONE, &desc,
        D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(textureUploadHeap.GetAddressOf())
    ));

    UpdateSubresources(cmdList, texture.Get(), textureUploadHeap.Get(), 0, 0, 1, &subresource);

    auto barrier = CD3DX12_RESOURCE_BARRIER::Transition(texture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);

    cmdList->ResourceBarrier(1, &barrier);
}