#include "Image.h"
Image::Image(){

}
Image::Image( float2 pos, int handle )
{
    this->pos    = pos;
    this->handle = handle;
}
Image::~Image()
{
}

void Image::Update()
{
}

void Image::Render()
{
    DrawRotaGraphF( f32( pos.x ), f32( pos.y ), 1, 0, handle, true );
}

void Image::Release()
{
}
