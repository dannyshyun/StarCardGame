#pragma once
struct Image final
{
public:
    Image();
    Image( int handle );
    ~Image();

    int    handle;
};
