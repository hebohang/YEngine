#pragma once

#include <assimp/Exporter.hpp>
#include <assimp/Importer.hpp>
#include <assimp/ProgressHandler.hpp>
#include <assimp/anim.h>
#include <assimp/mesh.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "d3dUtil.h"
#include "SkinnedData.h"

struct FbxMesh
{
    std::vector<Vertex> vertices;
    std::vector<int32_t> indices;
    UINT MaterialIndex;

    FbxMesh(std::vector<Vertex>& vertices, std::vector<int32_t>& indices, UINT MaterialIndex)
        :vertices(vertices), indices(indices), MaterialIndex(MaterialIndex)
    {

    }
};

class FbxLoader
{
public:
    struct FbxMaterial
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

    bool LoadFbx(const std::string& filename,
        SkinnedData& skinInfo);

    std::vector<FbxMaterial> mats;
    std::vector<FbxMesh> FbxMeshes;
    std::vector<Vertex> FbxVertices;
    std::vector<int32_t> FbxIndices;
    std::vector<Subset> FbxSubsets;
    SkinnedData FbxSkinnedData;

    int SubsetId = -1;
    int FbxFaceCount = 0;
private:
    void ProcessNode(const aiScene* scene, aiNode* node);
    FbxMesh ProcessMesh(const aiScene* scene, aiMesh* ai_mesh);
    void LoadBones(const aiMesh* mesh);
    void SetupMeshMaterial(const aiScene* scene, const aiMesh* mesh);
};