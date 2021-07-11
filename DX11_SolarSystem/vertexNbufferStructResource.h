#pragma once
#include <D3D11.h>
#include <D3DX11.h>
#include <xnamath.h>

const int SOLAR_SYSTEM_SIZE = 9;	// �¾�,������ȭ����õ��
const float PI = 3.14f;

struct ConstantBuffer
{
	XMMATRIX mWorld;
	XMMATRIX mView;
	XMMATRIX mProjection;
};

struct VertexType
{
	XMFLOAT3 pos;
	XMFLOAT2 texture;
	XMFLOAT3 normal;
};

typedef struct
{
	int vIndex1, vIndex2, vIndex3;
	int tIndex1, tIndex2, tIndex3;
	int nIndex1, nIndex2, nIndex3;
}FaceType;