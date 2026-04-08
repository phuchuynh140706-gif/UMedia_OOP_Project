#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
private:
    string username;
    string password;
    vector<string> playlist; // Lưu danh sách các ID (vd: "M01", "S01") mà user đã thích

public:
    // Constructor khởi tạo tài khoản
    User(string _user, string _pass) : username(_user), password(_pass) {}

    // Hàm kiểm tra đăng nhập
    bool login(string inputUser, string inputPass) const {
        return (username == inputUser && password == inputPass);
    }

    // Các hàm Getter
    string getUsername() const { return username; }
    
    // BẮT BUỘC PHẢI CÓ HÀM NÀY ĐỂ BÊN NGOÀI LẤY DATA ĐEM ĐI LƯU
    vector<string> getPlaylist() const { return playlist; } 

    // Hàm thêm phim/nhạc vào Playlist (Chỉ lưu trên RAM)
    void addToPlaylistLocal(string mediaId) {
        playlist.push_back(mediaId);
    }

    // Hàm này dùng khi user bấm nút trên app (Chỉ lưu trên RAM)
    void addToPlaylist(string mediaId) {
        playlist.push_back(mediaId);
        
        // ĐÃ XÓA dòng gọi FileManager ở đây để tránh lỗi vòng lặp!
        // Việc gọi FileManager sẽ do file main.cpp hoặc giao diện Qt đảm nhận.
        
        cout << "[System] Da them " << mediaId << " vao Playlist tam thoi cua " << username << "!" << endl;
    }

    // Hàm in Playlist
    void showPlaylist() const {
        cout << "\n=== PLAYLIST CUA " << username << " ===" << endl;
        if (playlist.empty()) {
            cout << "(Chua co gi trong Playlist)" << endl;
            return;
        }
        for (const string& id : playlist) {
            cout << "-> ID Yeu Thich: " << id << endl;
        }
        cout << "=========================" << endl;
    }
};