#pragma once
#include <GameObjects/Deck.h>
#include <GameObjects/Hand.h>
//---------------------------------------------------------------------------------
//	プレイヤークラス
//---------------------------------------------------------------------------------
class Player : public Base
{
public:
    Player( int image );
    void Init() override;     //	初期化処理
    void Update() override;   //	更新処理
    void Render() override;   //	描画処理
    void Release() override;  //	終了処理

    void SelectCard( std::shared_ptr<CardBase> card );
    void CheckTouch( std::shared_ptr<CardBase> card );

    void ClickOk();

private:
    std::unique_ptr<Deck> deck;
    std::unique_ptr<Hand> hand;
};
