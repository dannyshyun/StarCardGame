﻿//---------------------------------------------------------------------------
//! @file   SceneSample.cpp
//! @brief  サンプルシーン
//---------------------------------------------------------------------------
#include "SceneSample.h"

BP_CLASS_IMPL( SceneSample, u8"サンプル" )

//---------------------------------------------------------------------------
//! 初期化
//---------------------------------------------------------------------------
bool SceneSample::Init()
{
    // 仮モデルの読み込み
    model_ = MV1LoadModel( ( TC ) "data/Sample/Player/model.mv1" );

    return true;
}

//---------------------------------------------------------------------------
//! 更新
//! @param  [in]    delta   経過時間
//---------------------------------------------------------------------------
void SceneSample::Update()
{
    // 仮モデルの設定
    MV1SetPosition( model_, { 0.0f, 0.0f, 0.0f } );
    MV1SetRotationXYZ( model_, { 0.0f, 0.0f, 0.0f } );
    MV1SetScale( model_, { 0.05f, 0.05f, 0.05f } );

    // カメラの設定
    SetCameraPositionAndTarget_UpVecY( { 0.f, 6.f, -15.f }, { 0.f, 5.f, 0.f } );
    SetupCamera_Perspective( 60.0f * DegToRad );
}

//---------------------------------------------------------------------------
//! 描画
//---------------------------------------------------------------------------
void SceneSample::Draw()
{
    // 仮モデルの描画
    MV1DrawModel( model_ );
}

//---------------------------------------------------------------------------
//! 終了
//---------------------------------------------------------------------------
void SceneSample::Exit()
{
    MV1DeleteModel( model_ );
}

//---------------------------------------------------------------------------
//! GUI表示
//---------------------------------------------------------------------------
void SceneSample::GUI()
{
}
