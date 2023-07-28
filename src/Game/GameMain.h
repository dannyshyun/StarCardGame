//---------------------------------------------------------------------------
//!	@file	GameMain.h
//! @brief	ゲームメイン
//---------------------------------------------------------------------------
#pragma once
#include "GameSystem/imageDatas.h"
//	初期化
bool GameInit();

//	更新
void GameUpdate();

//	描画
void GameDraw();

//	終了
void GameExit();

enum GAME_TURN
{
    LOAD_TURN = 0,
    SHUFFLE_TURN,
    DEAL_TURN,
    MOVE_TURN,
    PLAYER_ATTACK_TURN,
    PLAYER_DEFENSE_TURN,
    NPC_ATTACK_TURN,
    NPC_DEFESE_TURN,
    RESULT_TURN,

    TURN_MAX
};
extern IMGcontroller IMGctrl;
extern int           Turn;