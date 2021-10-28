#pragma once
#include "d3dUtil.h"
#include "SkinnedData.h"
#include "Camera.h"

struct SkinnedModelInstance
{
	SkinnedData* SkinnedInfo = nullptr;
	std::vector<DirectX::XMFLOAT4X4> FinalTransforms;
	std::string ClipName;
	float TimePos = 10000.0f; // SkinnedInfo->GetClipEndTime(ClipName);

	DirectX::XMFLOAT4X4 World = MathHelper::Identity4x4();
	Camera ModelCamera;

	bool bPlay = false;

	// Called every frame and increments the time position, interpolates the 
	// animations for each bone based on the current animation clip, and 
	// generates the final transforms which are ultimately set to the effect
	// for processing in the vertex shader.
	void UpdateSkinnedAnimation(float dt)
	{
		TimePos += dt;

		// 如果bPlay，就播放动画，并且停止
		// 通过TimePos归零，即小于动画时间，来播放动画
		if ((TimePos > SkinnedInfo->GetClipEndTime(ClipName)) && bPlay)
		{
			TimePos = 0.0f;
			bPlay = false;
		}

		// Compute the final transforms for this time position.
		SkinnedInfo->GetFinalTransforms(ClipName, TimePos, FinalTransforms);
	}
};

class YSkinnedModel
{
private:
	struct SubmeshGeometry
	{
		UINT IndexCount = 0;
		UINT StartIndexLocation = 0;
		INT BaseVertexLocation = 0;

		// Bounding box of the geometry defined by this submesh. 
		// This is used in later chapters of the book.
		DirectX::BoundingBox Bounds;
	};

	struct SkinnedVertex
	{
		DirectX::XMFLOAT3 Pos;
		DirectX::XMFLOAT3 Normal;
		DirectX::XMFLOAT2 TexC;
		DirectX::XMFLOAT3 TangentU;
		DirectX::XMFLOAT3 BoneWeights;
		BYTE BoneIndices[4];
	};

	struct Subset
	{
		UINT Id = -1;
		UINT VertexStart = 0;
		UINT VertexCount = 0;
		UINT FaceStart = 0;
		UINT FaceCount = 0;
	};

	struct Material
	{
		std::string Name;

		DirectX::XMFLOAT4 DiffuseAlbedo = { 1.0f, 1.0f, 1.0f, 1.0f };
		DirectX::XMFLOAT3 FresnelR0 = { 0.01f, 0.01f, 0.01f };
		float Roughness = 0.8f;
		bool AlphaClip = false;

		std::string MaterialTypeName;
		std::string DiffuseMapName;
		std::string NormalMapName;
	};

public:
	void Load(std::string SkinnedModelFilename);

	std::vector<SkinnedVertex> mVertices;
	std::vector<std::uint16_t> mIndices;

	std::vector<Subset> mSkinnedSubsets;
	std::vector<Material> mSkinnedMats;
};