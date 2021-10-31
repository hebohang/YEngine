#include "pch.h"
#include "Model.h"
#include "Helpers.h"
#include "LoadFbx.h"

void YBaseModel::LoadIntoMeshGeometries(MeshGeometries& mGeometries, std::string MeshGeometryName, YDevice& md3dDevice, YCommandList& mCommandList)
{
	auto geo = std::make_unique<MeshGeometry>();
	geo->Name = MeshGeometryName;

	const UINT vbByteSize = (UINT)YModelVertices.size() * sizeof(Vertex);
	const UINT ibByteSize = (UINT)YModelIndices.size() * sizeof(std::int32_t);

	ThrowIfFailed(D3DCreateBlob(vbByteSize, &geo->VertexBufferCPU));
	CopyMemory(geo->VertexBufferCPU->GetBufferPointer(), YModelVertices.data(), vbByteSize);

	ThrowIfFailed(D3DCreateBlob(ibByteSize, &geo->IndexBufferCPU));
	CopyMemory(geo->IndexBufferCPU->GetBufferPointer(), YModelIndices.data(), ibByteSize);

	geo->VertexBufferGPU = d3dUtil::CreateDefaultBuffer(md3dDevice.Get(),
		mCommandList.Get(), YModelVertices.data(), vbByteSize, geo->VertexBufferUploader);

	geo->IndexBufferGPU = d3dUtil::CreateDefaultBuffer(md3dDevice.Get(),
		mCommandList.Get(), YModelIndices.data(), ibByteSize, geo->IndexBufferUploader);

	geo->VertexByteStride = sizeof(Vertex);
	geo->VertexBufferByteSize = vbByteSize;
	geo->IndexFormat = DXGI_FORMAT_R32_UINT;
	geo->IndexBufferByteSize = ibByteSize;

	assert(YModelSubsets.size() > 0);

	for (UINT i = 0; i < (UINT)YModelSubsets.size(); ++i)
	{
		SubmeshGeometry submesh;
		std::string name = "sm_" + std::to_string(i);

		submesh.IndexCount = (UINT)YModelSubsets[i].FaceCount * 3;
		submesh.StartIndexLocation = YModelSubsets[i].FaceStart * 3;
		submesh.BaseVertexLocation = 0;

		geo->DrawArgs[name] = submesh;
	}

	mGeometries[geo->Name] = std::move(geo);
}

void YPbrBaseModel::LoadModel()
{
	FbxLoader fbxloader;
	fbxloader.LoadFbx(FileName);
	YModelVertices = fbxloader.FbxVertices;
	YModelIndices = fbxloader.FbxIndices;
	YModelSubsets = fbxloader.FbxSubsets;

	YModelPbrMaps = fbxloader.FbxPbrMaps;
}
