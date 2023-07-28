#pragma once

enum ActionSuit
{
    ACTION_MOVE = 0,
    ACTION_SWORD,
    ACTION_GUN,
    ACTION_DEFENSE,

    ACTION_MAX
};

class ActionCard : public CardBase
{
public:
    ActionCard( int image, u32 value, u32 part, std::string suit );
    ~ActionCard();
    void Init() override;
    void Update() override;
    void Render( bool is_show ) override;
    void Release() override;

    [[nodiscard]] std::string GetSuit() const;

protected:
    std::string suit = 0;
};
