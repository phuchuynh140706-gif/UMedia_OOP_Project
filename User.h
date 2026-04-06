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

    string getUsername() const { return username; }

    // Hàm thêm phim/nhạc vào Playlist cá nhân
    void addToPlaylist(string mediaId) {
        // Có thể thêm logic kiểm tra trùng lặp ở đây nếu muốn hoàn hảo hơn
        playlist.push_back(mediaId);
        cout << "[System] Da them " << mediaId << " vao Playlist cua " << username << "!" << endl;
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