==================================================
  BÁO CÁO HOÀN THÀNH CORE BACKEND - ĐỒ ÁN UMEDIA
  Người thực hiện: Phúc (Leader)
  Ngày cập nhật: 06/04/2026
==================================================

1. TỔNG QUAN KIẾN TRÚC ĐÃ HOÀN THIỆN:
Hệ thống OOP Backend đã chạy ổn định, không có lỗi rò rỉ bộ nhớ, bao gồm các file sau:
- Interfaces.h : Chứa các interface Downloadable, Shareable.
- Media.h : Class gốc (Base class).
- DerivedMedia.h : Chứa class Movie, Music, PremiumMovie.
- ShortVideo.h : Chứa class ShortVideo.
- MediaFactory.h : Bộ máy cắt chuỗi string thành Object OOP.
- MediaManager.h : Bộ não quản lý danh sách, tìm kiếm, sắp xếp và phát media.
- User.h : Quản lý đăng nhập và Playlist cá nhân.
- main.cpp : File test tổng hợp toàn bộ luồng chạy.

2. HƯỚNG DẪN DÀNH CHO SƠN (FILE I/O):
- Nhiệm vụ: Đọc file "data.txt" (hoặc json).
- Điểm kết nối: Sơn lấy từng dòng đọc được, truyền vào hàm `MediaFactory::createMediaFromLine(chuoi_string)`. 
- Hàm này sẽ tự động trả về 1 đối tượng Media, Sơn chỉ việc tống nó vào `MediaManager::addMedia()` là xong. Không cần quan tâm bên trong Phúc viết gì.

3. HƯỚNG DẪN DÀNH CHO NHƯ (FRONTEND UI Qt):
- Nhiệm vụ: Thiết kế giao diện bằng Qt.
- Điểm kết nối: Khi cần lấy data in lên màn hình, gọi hàm `app.showAllMedia()` hoặc thiết kế lại hàm getter để lấy list string.
- Khi user bấm nút Play, chỉ cần gọi `app.playItem("ID_CUA_MEDIA")`. Hàm ảo (virtual) sẽ tự động biết đó là nhạc hay phim để xử lý tiếp.

** Lưu ý team: Cứ bám sát file main.cpp để hiểu luồng chạy. Cố lên anh em!