#pragma once
#include <D3D11.h>
#include <D3DX11.h>
#include <xnamath.h>

struct ConstantBuffer
{
	XMMATRIX mWorld;
	XMMATRIX mView;
	XMMATRIX mProjection;
};

class CameraClass
{
private:
	ConstantBuffer coordinateConstantBuffer;

	XMVECTOR Eye = XMVectorSet(0.0f, 1.0f, -5.0f, 0.0f);
	XMVECTOR At = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	ID3D11Device* m_pd3dDevice = NULL;
	ID3D11DeviceContext* m_pImmediateContext = NULL;
	ID3D11Buffer* m_pConstantBuffer = NULL;

public:
	HRESULT Init(const float width, const float height, 
		ID3D11Device* m_pd3dDevice, ID3D11DeviceContext* m_pImmediateContext);

	ConstantBuffer* GetCoordinateConstantBuffer();
	void Update();
	void Shutdown();
};

