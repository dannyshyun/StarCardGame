#include "Image.h"
Image::Image()
{
}

Image::Image( int handle )
{
    this->handle = handle;
}

Image::~Image()
{
}

int Image::GetImgHandle() const
{
    return this->handle;
}

float2 Image::GetImgSize() const
{
    float x, y;
    GetGraphSizeF( this->handle, &x, &y );
    return float2( x, y );
}
