#pragma once
#include <memory>
#include <map>
#include <vector>
#include <string>
class IMGcontroller
{
public:
    IMGcontroller();
    void Init();
    void Release();
    int  GetCardIMGdata( std::string suit, u32 value = 1 );
    int  GetUIIMGdata( std::string name );

private:
    //   suit         datas vector (value = index + 1)
    std::unique_ptr<std::map<std::string, std::vector<int>>> card_IMG_list;
    //   name         data
    std::unique_ptr<std::map<std::string, int>> UI_IMG_list;
};
