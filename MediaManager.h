#pragma once
#include <vector>
#include "DerivedMedia.h"
#include <iostream>
#include <algorithm>

using namespace std;

class MediaManager{
private:
    vector<Media*> database;
public:
//Destructor: dọn dẹp ram trước khi tắt app
    ~MediaManager(){
        for (Media* m: database){
            delete m;
        }
        database.clear();
        cout << "[System] Da giai phong toan bo bo nho" <<endl;
    }
    void addMedia(Media* m){
        database.push_back(m);
    }

    void showAllMedia() const {
        cout << "\n=== DANH SACH TONG HOP ===" <<endl;
        for (Media* m : database )
        {
            m->showInfo();
        }
       cout << "========================\n";
    }
   //hàm logic khi bấm nút play
   void playItem(string searchId ) const {
    for (Media * m : database) {
        if (m->getId() == searchId)
        {
            m->play();
            return;
        }
    }
    cout <<"[Loi] Khong tim thay ID: " << searchId <<endl;
   }
   // Tim kiem theo ten (Dung cho thanh Search )
    vector<Media*> searchByTitle(string keyword) {
        vector<Media*> results;
        for (auto m : database) {
            // Chuyen ve chu thuong de tim kiem khong phan biet hoa thuong
            if (m->getTitle().find(keyword) != string::npos) {
                results.push_back(m);
            }
        }
        return results;
    }

    // Sap xep theo thoi luong (Dung cho tinh nang Sort cua app)
    void sortByDuration() {
        sort(database.begin(), database.end(), [](Media* a, Media* b) {
            return a->getDuration() < b->getDuration();
        });
    }

    // Ham tra ve toan bo database de Nhu do du lieu len UI
    const vector<Media*>& getRawData() const { return database; }
};