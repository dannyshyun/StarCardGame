#pragma once

//---------------------------------------------------------------------------------
//	�m�o�b�N���X
//---------------------------------------------------------------------------------
class Npc : public Player
{
public:
    Npc( int image );
    void Init() override;     //	����������
    void Update() override;   //	�X�V����
    void Render() override;   //	�`�揈��
    void Release() override;  //	�I������

    void SelectCard( CardBase card );

private:
    std::unique_ptr<Deck> deck;
    std::unique_ptr<Hand> hand;
};
