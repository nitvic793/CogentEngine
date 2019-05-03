#pragma once
#include <DirectXMath.h>
#include "Mesh.h"
#include "Material.h"
using namespace DirectX;
class Entity
{
public:
	Entity(Mesh* mesh, char* address, D3D12_GPU_DESCRIPTOR_HANDLE hp);
	~Entity();

	XMFLOAT3 GetPosition(); 

	void SetPosition(XMFLOAT3 position);
	void SetScale(XMFLOAT3 scale);
	void SetRotation(XMFLOAT3 rotation);

	void Move(float x, float y, float z);
	void Rotate(float x, float y, float z);

	

	Mesh* GetMesh();
	void SetMesh(Mesh* mesh);
	XMFLOAT4X4 GetWorldMatrix();
	void UpdateWorldMatrix();
	char* GetAddress();

	Material* GetMaterial();
	D3D12_GPU_DESCRIPTOR_HANDLE GetHandle();
	D3D12_GPU_DESCRIPTOR_HANDLE GetSRVHandle();
	void SetSRVHandle(D3D12_GPU_DESCRIPTOR_HANDLE srvHandle);
	BoundingOrientedBox& GetBoundingOrientedBox();
	

private:
	XMFLOAT4X4 worldMatrix;
	XMFLOAT3 position;
	XMFLOAT3 rotation;
	XMFLOAT3 scale;
	Mesh* mesh;
	Material* material;
	char* gpuAddress;
	D3D12_GPU_DESCRIPTOR_HANDLE handle;
	D3D12_GPU_DESCRIPTOR_HANDLE srvHandle;
	UINT64 handlePtr;
	BoundingOrientedBox boundingOrientedBox;
	BoundingOrientedBox box;

};

