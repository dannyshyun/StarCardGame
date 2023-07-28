#pragma once

//---------------------------------------------------------------------------------
//	‚m‚o‚bƒNƒ‰ƒX
//---------------------------------------------------------------------------------
class Npc : public Player
{
public:
    Npc( int image );
    void Init() override;     //	‰Šú‰»ˆ—
    void Update() override;   //	XVˆ—
    void Render() override;   //	•`‰æˆ—
    void Release() override;  //	I—¹ˆ—

    void SelectCard( CardBase card );

private:
    std::unique_ptr<Deck> deck;
    std::unique_ptr<Hand> hand;
};
