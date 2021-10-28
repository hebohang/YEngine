#include "pch.h"
#include "LoadFbx.h"

bool FbxLoader::LoadFbx(const std::string& filename, std::vector<FbxMaterial>& mats, SkinnedData& skinInfo)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(filename, aiProcess_Triangulate | aiProcess_ConvertToLeftHanded | aiProcess_GenNormals);

	ProcessNode(scene, scene->mRootNode);
	
	return true;
}

void FbxLoader::ProcessNode(const aiScene* scene, aiNode* node)
{
	for (size_t i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* ai_mesh = scene->mMeshes[node->mMeshes[i]];
		FbxMeshes.push_back(ProcessMesh(scene, ai_mesh));
	}

	for (size_t i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(scene, node->mChildren[i]);
	}
}

FbxMesh FbxLoader::ProcessMesh(const aiScene* scene, aiMesh* ai_mesh)
{
	std::vector<SkinnedVertex> vertices;
	std::vector<UINT> indices;
	Subset subset;
	
	// TODO Bone
	// std::vector<BoneData> vertexBoneData(mesh->mNumVertices);
	LoadBones(ai_mesh);

	for (size_t i = 0; i < ai_mesh->mNumVertices; i++) 
	{
		SkinnedVertex vertex;
		vertex.Pos.x = ai_mesh->mVertices[i].x;
		vertex.Pos.y = ai_mesh->mVertices[i].y;
		vertex.Pos.z = ai_mesh->mVertices[i].z;

		vertex.Normal.x = ai_mesh->mNormals[i].x;
		vertex.Normal.y = ai_mesh->mNormals[i].y;
		vertex.Normal.z = ai_mesh->mNormals[i].z;

		if (ai_mesh->mTextureCoords[0])
		{
			vertex.TexC.x = ai_mesh->mTextureCoords[0][i].x;
			vertex.TexC.y = ai_mesh->mTextureCoords[0][i].y;
		}
		else 
		{
			vertex.TexC = { 0.0f, 0.0f };
		}

		// TODO Bone
		//vertex.BoneWeights.x = vertexBoneData[i].weights[0];
		//vertex.BoneWeights.y = vertexBoneData[i].weights[1];
		//vertex.BoneWeights.z = vertexBoneData[i].weights[2];

		//for (size_t j = 0; j < NUM_BONES_PER_VERTEX; j++)
		//	vertex.boneIndices[j] = vertexBoneData[i].boneIndex[j];

		vertices.push_back(vertex);
	}

	for (size_t i = 0; i < ai_mesh->mNumFaces; i++) 
	{
		aiFace face = ai_mesh->mFaces[i];
		for (size_t j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	// TODO Material
	//std::vector<UINT> diffuseMaps;
	//if (mesh->mMaterialIndex >= 0) {
	//	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	//	diffuseMaps = LoadMaterialTextures(material, aiTextureType_DIFFUSE);
	//}
	//UINT materialIndex = SetupMaterial(diffuseMaps);

	SubsetId++;
	subset.Id = SubsetId;
	subset.VertexStart = FbxVertices.size();
	subset.VertexCount = vertices.size();
	subset.FaceStart = FbxFaceCount;
	subset.FaceCount = ai_mesh->mNumFaces;

	FbxFaceCount += ai_mesh->mNumFaces;

	FbxVertices.insert(FbxVertices.end(), vertices.begin(), vertices.end());
	FbxIndices.insert(FbxIndices.end(), indices.begin(), indices.end());

	FbxSubsets.push_back(subset);

	return FbxMesh(vertices, indices, -1);
}

void FbxLoader::LoadBones(const aiMesh* mesh)
{
	for (size_t i = 0; i < mesh->mNumBones; i++)
	{

	}
}
