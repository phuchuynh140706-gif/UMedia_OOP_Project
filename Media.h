#pragma once
#include <iostream>
#include <string>

using namespace std;

class Media  {
protected: 
    string id;
    string title;
    int duration;
    string genre;
public: 
    Media (string _id,string _title,int _duration, string _genre) 
        : id(_id), title(_title), duration(_duration), genre(_genre) {}
    virtual ~Media() = default; // Tránh Memory Leak
    // Các hàm Getter cơ bản 
    string getId() const {return id;}
    string getTitle() const {return title;}
    // Các hàm Getter cơ bản
    int getDuration() const { return duration; }
    string getGenre() const { return genre; }
   
    // Các hàm ảo (Polymorphism)
    virtual void play() const = 0;
    virtual void showInfo() const = 0;
};

