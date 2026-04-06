#pragma once
#include <iostream>
#include <string>

using namespace std;

// Interfaces cho các nội dung tải xuống
class Downloadable {
public:
    virtual void download () const = 0;
    virtual ~Downloadable() = default;
};

//Interfaces cho các nội dung có thể chia sẻ 
class Shareable {
public:
    virtual void share() const =0 ;
    virtual ~Shareable() = default;
};

