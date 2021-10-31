#pragma once

#include "d3dUtil.h"

using namespace YVertexUtil;

class YBaseModel
{
public:
	using MeshGeometries = std::unordered_map<std::string, std::unique_ptr<MeshGeometry>>;
	using YDevice = Microsoft::WRL::ComPtr<ID3D12Device>;
	using YCommandList = Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>;

	void LoadIntoMeshGeometries(MeshGeometries& mGeometries, std::string MeshGeometryName, YDevice& md3dDevice, YCommandList& mCommandList);

	std::vector<Vertex> YModelVertices;
	std::vector<int32_t> YModelIndices;
	std::vector<Subset> YModelSubsets;
	std::string FileName;
};

class YPbrBaseModel : public YBaseModel
{
public:
	std::vector<PbrMaps> YModelPbrMaps;

	void LoadModel();
};