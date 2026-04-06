#include <iostream>
#include <vector>
#include <string>
#include "MediaManager.h"
#include "MediaFactory.h"
#include "User.h" // Nhớ include User.h vào đây

using namespace std;

int main() {
    // 1. KHỞI TẠO HỆ THỐNG VÀ NẠP DỮ LIỆU
    MediaManager app;
    vector<string> fakeFileLines = {
        "1|M01|Avengers: Endgame|180|Action|Russo Brothers|8.4",
        "2|S01|Muon Roi Ma Sao Con|4|Pop|Son Tung M-TP",
        "3|V01|Highlight Da Bong Cực Căng|2|Sport|TheThao247|15000"
    };

    for (const string& line : fakeFileLines) {
        Media* newMedia = MediaFactory::createMediaFromLine(line);
        if (newMedia != nullptr) app.addMedia(newMedia);
    }

    // 2. KHỞI TẠO USER (Giả sử Sơn đã đọc file account.txt và cấp cho bạn thông tin này)
    User currentUser("phucleader", "123456");

    cout << "=== MAN HINH DANG NHAP ===" << endl;
    string inputU, inputP;
    
    // Test đăng nhập tĩnh (Bạn có thể dùng cin >> để nhập từ bàn phím cho ngầu)
    inputU = "phucleader";
    inputP = "123456";

    if (currentUser.login(inputU, inputP)) {
        cout << "-> Dang nhap thanh cong! Xin chao " << currentUser.getUsername() << "\n" << endl;
        
        // Hiện danh sách cho User xem
        app.showAllMedia();

        // User thấy phim Avengers (M01) hay quá, bấm nút "Thêm vào Playlist"
        currentUser.addToPlaylist("M01");

        // User lướt tới video TikTok (V01) thấy hài, lại thêm vào Playlist
        currentUser.addToPlaylist("V01");

        // Xem lại Playlist cá nhân
        currentUser.showPlaylist();

        // User mở xem Playlist và bấm xem phim M01
        cout << "\n[User dang mo Playlist va bam Play bo phim dau tien...]" << endl;
        app.playItem("M01");

    } else {
        cout << "-> Sai tai khoan hoac mat khau. Vui long thu lai!" << endl;
    }

    return 0;
}