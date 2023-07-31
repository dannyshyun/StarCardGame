#pragma once

class Image
{
public:
    Image();
    Image( int handle );
    ~Image();

    int    GetImgHandle() const;
    float2 GetImgSize() const;

private:
    int handle = -1;
};