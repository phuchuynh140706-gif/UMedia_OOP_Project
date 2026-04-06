#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "DerivedMedia.h" // Nhớ include file chứa Movie, Music, ShortVideo
#include "ShortVideo.h"
using namespace std;

class MediaFactory {
public:
    static Media* createMediaFromLine(const string& line) {
        stringstream ss(line);
        string type, id, title, durationStr, genre;
        
        getline(ss, type, '|');
        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, durationStr, '|');
        getline(ss, genre, '|');

        int duration = stoi(durationStr);

        if (type == "1") { 
            string director, imdbStr;
            getline(ss, director, '|');
            getline(ss, imdbStr, '|');
            return new Movie(id, title, duration, genre, director, stof(imdbStr));
        } 
        else if (type == "2") {
            string artist;
            getline(ss, artist, '|');
            return new Music(id, title, duration, genre, artist);
        }
        else if (type == "3") {
            string uploader, likesStr;
            getline(ss, uploader, '|');
            getline(ss, likesStr, '|');
            return new ShortVideo(id, title, duration, genre, uploader, stoi(likesStr));
        }
        return nullptr;
    }
};