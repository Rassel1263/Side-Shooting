#include "DXUT.h"

Scene* nowScene = NULL;

Game::~Game()
{
    SAFE_DELETE(nowScene);
    SAFE_RELEASE(pSprite);
    SAFE_RELEASE(pLine);
}

void Game::Init()
{
#ifdef _DEBUG
    RECT rectArea;
    int SM_Height = GetSystemMetrics(SM_CYSCREEN);
    SystemParametersInfo(SPI_GETWORKAREA, 0, (PVOID)&rectArea, 0);

    TaskHeight = (SM_Height - (rectArea.bottom - rectArea.top));
#endif

    ChangeScene(new GameScene());

    D3DXVECTOR3 vEyePt = { 0.0f, 0.0f, -10.0f };
    D3DXVECTOR3 vLookatPt = { 0.0f, 0.0f, 0.0f };
    D3DXVECTOR3 vUpVec = { 0.0f, 1.0f, 0.0f };
    D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
    DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &matView);

    D3DXMatrixOrthoLH(&matProj, screenWidth, screenHeight, 0.01f, 100.0f);
    DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &matProj);

    D3DXCreateSprite(DXUTGetD3D9Device(), &pSprite);
    D3DXCreateLine(DXUTGetD3D9Device(), &pLine);

    destCameraPos = cameraPos = D3DXVECTOR2(-960, -540);

    Input::GetInstance().Start();

    DXUTGetD3D9Device()->SetRenderState(D3DRS_ZENABLE, FALSE);
    DXUTGetD3D9Device()->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
}

void Game::Update(float deltaTime)
{
    Input::GetInstance().Update();

    D3DXVec2Lerp(&cameraPos, &cameraPos, &destCameraPos, 0.1f);
    D3DXVec2Lerp(&cameraScale, &cameraScale, &destCameraScale, 0.1f);
    D3DXVec2Lerp(&cameraQuaken, &cameraQuaken, &destCameraQuaken, 0.1f);


    if (nextScene)
    {
        nowScene = nextScene;
        nowScene->Init();
        nextScene = NULL;
    }

    D3DXMATRIX matScale;
    D3DXMatrixScaling(&matScale, cameraScale.x, cameraScale.y, 1.0f);

    D3DXMATRIX matPos;
    D3DXMatrixTranslation(&matPos, ((rand() % 2 ? 1 : -1) * cameraQuaken.x) - cameraPos.x, ((rand() % 2 ? 1 : -1) * cameraQuaken.y) - cameraPos.y, 0.0f);

    matWorld = matScale * matPos;
    DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &matWorld);


    if (nowScene)
        nowScene->Update(deltaTime * timeScale);
}

void Game::Render()
{
    pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    if (nowScene)
        nowScene->Render();

    pSprite->End();

    while (!lines.empty()) {
        LineData data = lines.front();
        lines.pop();
        pLine->SetWidth(2.0f);
        pLine->Begin();
        //
        //    float _41 = mat._41 - (cameraPos.x + screenWidth / 2);
        //    float _42 = -mat._42 - (cameraPos.y + screenHeight / 2);
        //    //float _42 = mat._42 - (cameraPos.y + screenHeight / 2);
        //
        //#ifdef DEBUG
        //    _42 -= TaskHeight / 2;
        //#endif // DEBUG
        D3DXVECTOR3 v[] = { D3DXVECTOR3(data.p1.x - 960, data.p1.y - 540, 0.0f), D3DXVECTOR3(data.p2.x - 960, data.p2.y - 540, 0.0f) };
        D3DXMATRIX retMat = data.mat * matWorld * matView * matProj;

        pLine->DrawTransform(v, 2, &retMat, data.color);
        pLine->End();
    }
}

void Game::DrawLine(D3DXVECTOR2 p1, D3DXVECTOR2 p2, D3DXMATRIX mat, D3DXCOLOR color)
{
    lines.push({ p1, p2, mat, color });
}

void Game::ChangeScene(Scene* nextScene)
{
    this->nextScene = nextScene;
}