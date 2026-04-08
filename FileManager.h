#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp" // Khai báo thư viện JSON vừa tải
#include "MediaManager.h"
#include "DerivedMedia.h" // Để gọi new Movie, new Music
#include "ShortVideo.h"
#include "User.h" 
using namespace std;
using json = nlohmann::json; // Viết tắt cho dễ gọi

class FileManager {
public:
    // HÀM ĐỌC DATA TỪ FILE JSON
    static void loadMediaFromJson(const string& filename, MediaManager& app) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "[Loi] Khong tim thay file " << filename << endl;
            return;
        }

        // 1. Nạp toàn bộ file vào biến JSON cực kỳ kỳ diệu và nhanh chóng
        json jData;
        file >> jData; 

        // 2. Duyệt qua từng object trong mảng JSON
        int count = 0;
        for (const auto& item : jData) {
            int type = item["type"];
            string id = item["id"];
            string title = item["title"];
            int duration = item["duration"];
            string genre = item["genre"];

            // Phân loại và khởi tạo Object OOP tương ứng
            if (type == 1) {
                string director = item["director"];
                float imdb = item["imdb"];
                app.addMedia(new Movie(id, title, duration, genre, director, imdb));
            } 
            else if (type == 2) {
                string artist = item["artist"];
                app.addMedia(new Music(id, title, duration, genre, artist));
            } 
            else if (type == 3) {
                string uploader = item["uploader"];
                int likes = item["likes"];
                app.addMedia(new ShortVideo(id, title, duration, genre, uploader, likes));
            }
            count++;
        }
        
        file.close();
        cout << "[System] Da tai thanh cong " << count << " items tu " << filename << "!\n" << endl;
    }

    // HÀM GHI LỊCH SỬ (Giữ nguyên)
    static void saveLog(const string& username, const string& action) {
        ofstream file("history.log", ios::app); 
        if (file.is_open()) {
            file << "[User: " << username << "] " << action << endl;
            file.close();
        }
    }
    // 3. HÀM XÁC THỰC ĐĂNG NHẬP VÀ LOAD PLAYLIST TỪ JSON
    static User* authenticateUser(const string& username, const string& password) {
        ifstream file("users.json");
        if (!file.is_open()) return nullptr;

        json jUsers;
        file >> jUsers;
        file.close();

        // Kiểm tra xem User có tồn tại không
        if (jUsers.contains(username)) {
            // Kiểm tra mật khẩu
            if (jUsers[username]["password"] == password) {
                // Khởi tạo User
                User* loggedInUser = new User(username, password);
                
                // Nạp danh sách Playlist cũ vào RAM
                for (const string& id : jUsers[username]["playlist"]) {
                    loggedInUser->addToPlaylistLocal(id); // Chỉ nạp vào RAM, không gọi hàm lưu file
                }
                return loggedInUser;
            }
        }
        return nullptr; // Sai tài khoản hoặc mật khẩu
    }

    // 4. HÀM GHI ĐÈ PLAYLIST MỚI XUỐNG FILE JSON
    static void updatePlaylistInJson(const string& username, const vector<string>& currentPlaylist) {
        ifstream fileIn("users.json");
        json jUsers;
        if (fileIn.is_open()) {
            fileIn >> jUsers;
            fileIn.close();
        }

        // Cập nhật lại mảng playlist của user này
        jUsers[username]["playlist"] = currentPlaylist;

        // Ghi ngược lại xuống file (tham số 4 để format JSON đẹp, thụt lề chuẩn)
        ofstream fileOut("users.json");
        fileOut << jUsers.dump(4); 
        fileOut.close();
    }
    // 5. HÀM TẠO TÀI KHOẢN MỚI (ĐĂNG KÝ)
    static bool registerUser(const string& username, const string& password) {
        ifstream fileIn("users.json");
        json jUsers;
        
        // Nếu file đã tồn tại thì đọc lên
        if (fileIn.is_open()) {
            fileIn >> jUsers;
            fileIn.close();
        }

        // BƯỚC A: Kiểm tra xem tên đăng nhập này đã có ai dùng chưa?
        if (jUsers.contains(username)) {
            return false; // Trả về false báo hiệu là bị trùng tên
        }

        // BƯỚC B: Khởi tạo tài khoản mới với mật khẩu và playlist rỗng
        jUsers[username] = {
            {"password", password},
            {"playlist", json::array()} // json::array() là mảng rỗng []
        };

        // BƯỚC C: Ghi ngược lại xuống file JSON
        ofstream fileOut("users.json");
        fileOut << jUsers.dump(4); 
        fileOut.close();

        // Ghi Log hệ thống
        saveLog(username, "Da tao tai khoan moi thanh cong!");

        return true; // Trả về true báo hiệu đăng ký thành công
    }
};