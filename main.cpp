#include <iostream>
#include <string>
#include "MediaManager.h"
#include "User.h"
#include "FileManager.h"

using namespace std;

int main() {
    cout << "=====================================" << endl;
    cout << "    KHOI DONG HE THONG UMEDIA" << endl;
    cout << "=====================================\n" << endl;

    // 1. KHỞI TẠO HỆ THỐNG & ĐỌC DATA TỪ JSON
    MediaManager app;
    FileManager::loadMediaFromJson("data.json", app);

    // 2. ĐĂNG NHẬP (Dùng hàm mới đọc từ users.json)
    cout << "--- MAN HINH DANG NHAP ---" << endl;
    User* currentUser = FileManager::authenticateUser("phucleader", "123456");

    if (currentUser != nullptr) {
        cout << "-> Dang nhap thanh cong! Xin chao " << currentUser->getUsername() << "\n" << endl;
        FileManager::saveLog(currentUser->getUsername(), "Dang nhap he thong");

        // 3. HIỆN DANH SÁCH MEDIA
        app.showAllMedia();

        // 4. TEST CHỨC NĂNG THÊM PLAYLIST (CHỖ CẦN SỬA LÀ ĐÂY!!!)
        cout << "\n[User thay phim M01 hay qua, bam nut Them vao Playlist...]" << endl;
        
        // BƯỚC A: Lưu vào RAM của hệ thống trước
        currentUser->addToPlaylist("M01"); 
        
        // BƯỚC B: Nhờ FileManager lấy cái RAM đó đem ép xuống ổ cứng JSON
        FileManager::updatePlaylistInJson(currentUser->getUsername(), currentUser->getPlaylist());

        // Test xem thử Playlist đã có chưa
        currentUser->showPlaylist();

        // 5. TEST CHỨC NĂNG PHÁT MEDIA
        cout << "\n[User bam Play phim M01...]" << endl;
        app.playItem("M01");
        FileManager::saveLog(currentUser->getUsername(), "Da xem phim: M01");

        // Dọn dẹp con trỏ User trước khi tắt app để không rò rỉ RAM
        delete currentUser; 
    } 
    else {
        cout << "-> Dang nhap that bai! Sai tai khoan hoac mat khau." << endl;
    }

    cout << "\n[System] Dang tat he thong... Kiem tra memory leak..." << endl;
    return 0; // Tới đây hệ thống tắt an toàn!
}