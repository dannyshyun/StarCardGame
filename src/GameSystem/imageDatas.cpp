#include "nlohmann/json.hpp"
#include "imageDatas.h"
#include <fstream>

using json = nlohmann::json;

IMGcontroller::IMGcontroller()
{
    card_IMG_list = std::make_unique<std::map<std::string, std::vector<int>>>();
    UI_IMG_list   = std::make_unique<std::map<std::string, int>>();
}
void IMGcontroller::Init()
{
    // load card images
    {
        // load json file
        std::ifstream file( "data/ImgPathDatas/Cards.json" );
        json          jfile = json::parse( file );
        // parse json object
        for( auto& obj: jfile )
        {
            u32         max_value = obj["max_value"].template get<short>();
            std::string suit      = obj["suit"];
            // create suit name of list
            ( *card_IMG_list )[suit] = std::vector<int>();
            for( u32 i = 0; i < max_value; i++ )
            {
                // get path from json file
                std::string path =
                    suit == "Back"  // check
                        ? obj["path"].template get<std::string>() +
                              ".jpg"                                 // true
                        : obj["path"].template get<std::string>() +  // false
                              std::to_string( i + 1 ) + ".jpg";
                // load image
                int img = LoadGraph( (const TCHAR*)path.c_str() );
                // push to the suit vector
                ( *card_IMG_list )[suit].push_back( img );
            }
        }
    }
    // load UI item images
    {
        // load json file
        std::ifstream file( "data/ImgPathDatas/UI.json" );
        json          jfile = json::parse( file );
        // parse json object
        for( auto& obj: jfile )
        {
            std::string name = obj["name"];
            std::string path = obj["path"];
            // load image
            int image = LoadGraph( (TC)path.c_str() );
            // push to the list
            ( *UI_IMG_list )[name] = image;
        }
    }
}

void IMGcontroller::Release()
{
}

int IMGcontroller::GetCardIMGdata( std::string suit, u32 value )
{
    return ( *card_IMG_list )[suit][value - 1];
}

int IMGcontroller::GetUIIMGdata( std::string name )
{
    return ( *UI_IMG_list )[name];
}
