#pragma once
#include "Media.h"
#include "Interfaces.h"

class ShortVideo : public Media, public Shareable {
private:
    int likes;
    string uploader;

public:
    ShortVideo(string _id, string _title, int _duration, string _genre, string _uploader, int _likes = 0)
        : Media(_id, _title, _duration, _genre), uploader(_uploader), likes(_likes) {}

    void play() const override {
        cout << "[TIKTOK] Dang cuon den video cua: " << uploader << " - " << title << endl;
    }

    void showInfo() const override {
        cout << "[Shorts] " << title << " by @" << uploader << " [" << likes << " Likes]" << endl;
    }

    void share() const override {
        cout << "Da sao chep link video ngan cua @" << uploader << " vao bo nho tam!" << endl;
    }

    void addLike() { likes++; }
};