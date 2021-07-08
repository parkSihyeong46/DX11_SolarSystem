#pragma once
#include <D3D11.h>
#include <xnamath.h>

struct VertexType
{
    XMFLOAT3 pos;
    XMFLOAT2 texture;
};

typedef struct
{
    int vIndex1, vIndex2, vIndex3;
    int tIndex1, tIndex2, tIndex3;
    int nIndex1, nIndex2, nIndex3;
}FaceType;

class CameraClass;
class ObjectClass
{
private:
    VertexType* m_vertices = NULL;
    ID3D11Buffer* m_pVertexBuffer = NULL;
    WORD* m_indices = NULL;
    ID3D11Buffer* m_pIndexBuffer = NULL;
    XMMATRIX mWorld;

    int vertexCount = 0;
    int indexCount = 0;
    UINT stride = sizeof(VertexType);
    UINT offset = 0;
public:
    VertexType* GetVertices();
    ID3D11Buffer* GetVertexBuffer();
    ID3D11Buffer* GetIndexBuffer();
    void SetVertexCount(int count);
    int GetIndexcount();
    UINT GetStride();
    UINT GetOffset();

    void SetVertexPosition(XMFLOAT3* vertexPosition, int vertexSize);
    void SetIndexPosition(FaceType* indexPosition, int indexSize);

    void DynamicAllocationVertices(const int size);
    HRESULT CreateVertexBuffer(ID3D11Device* pd3dDevice);
    HRESULT CreateIndexBuffer(ID3D11Device* pd3dDevice, int byteWidth);

    void Update(ID3D11DeviceContext* m_pImmediateContext, CameraClass* cameraClass, float deltaTime);
    void Render(ID3D11DeviceContext* m_pImmediateContext, int size);

    ObjectClass();
    ~ObjectClass();
};

