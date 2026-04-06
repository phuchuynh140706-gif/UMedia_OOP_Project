#pragma once
#include "Media.h"
#include "Interfaces.h"

// 1. Phim (Kế thừa đơn)
class Movie : public Media {
private:
    string director;
    float imdbScore;

public:
    Movie(string _id, string _title, int _duration, string _genre, string _director, float _imdb)
        : Media(_id, _title, _duration, _genre), director(_director), imdbScore(_imdb) {}

    void play() const override {
        cout << "[NETFLIX] Dang phat phim: " << title << " | Dao dien: " << director << endl;
    }

    void showInfo() const override {
        cout << "[Movie] " << title << " (" << genre << ") - IMDb: " << imdbScore << endl;
    }
};

// 2. Nhạc (Kế thừa đơn)
class Music : public Media {
private:
    string artist;

public:
    Music(string _id, string _title, int _duration, string _genre, string _artist)
        : Media(_id, _title, _duration, _genre), artist(_artist) {}

    void play() const override {
        cout << "[SPOTIFY] Dang phat nhac: " << title << " - The hien: " << artist << endl;
    }

    void showInfo() const override {
        cout << "[Music] " << title << " - " << artist << endl;
    }
};

// 3. Phim Độc Quyền / Premium Content (ĐA KẾ THỪA)
// Vừa là Phim, vừa có thể Tải xuống, vừa có thể Chia sẻ
class PremiumMovie : public Movie, public Downloadable, public Shareable {
private:
    float price;

public:
    PremiumMovie(string _id, string _title, int _duration, string _genre, string _director, float _imdb, float _price)
        : Movie(_id, _title, _duration, _genre, _director, _imdb), price(_price) {}

    // Implement các hàm của Interface
    void download() const override {
        cout << "Dang tai xuong noi dung Premium: " << getTitle() << " (Gia: $" << price << ")" << endl;
    }

    void share() const override {
        cout << "Chia se link phim Premium: " << getTitle() << endl;
    }
};