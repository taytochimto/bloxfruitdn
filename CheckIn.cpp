#include "CheckIn.h"

// Hàm này có nhiệm vụ chặn nhập chữ vào ô số, 
// VÀ dọn sạch luôn phím Enter thừa để không bị trôi lệnh ở các bước sau
int nhapSoNguyenSafe() {
    int value;
    while (true) {
        if (wcin >> value) {
            // Nhập đúng số -> Xóa phím Enter (\n) còn sót lại trong bộ nhớ đệm
            wcin.ignore(10000, L'\n'); 
            return value;
        } else {
            // Nhập sai (nhập chữ) -> Xóa cờ báo lỗi và dọn bộ nhớ đệm
            wcin.clear(); 
            wcin.ignore(10000, L'\n');
            wcout << RED << L"Lỗi! Vui lòng chỉ nhập SỐ: " << RESET;
        }
    }
}

void checkIn(vector<Phong>& dsPhong) {
    wcout << L"Nhập số phòng muốn Check-in: ";
    int soPhong = nhapSoNguyenSafe();

    for (auto& phong : dsPhong) {
        if (phong.soPhong == soPhong) {
            if (phong.daDat) {
                wcout << RED << L"Phòng này đã có người ở!\n" << RESET;
                return;
            }
            
            // Bắt đầu nhập thông tin khách (Dùng getline để lấy được cả họ và tên có dấu cách)
            wcout << L"Nhập tên khách hàng (VD: Nguyễn Văn A): ";
            getline(wcin, phong.khach.ten);
            
            wcout << L"Nhập số CCCD: ";
            getline(wcin, phong.khach.cccd);
            
            wcout << L"Nhập Số Điện Thoại: ";
            getline(wcin, phong.khach.sdt);
            
            wcout << L"Nhập số ngày dự kiến ở: ";
            phong.soNgayO = nhapSoNguyenSafe();

            // Cập nhật trạng thái phòng
            phong.daDat = true;
            wcout << GREEN << L"Check-in phòng " << soPhong << L" thành công!\n" << RESET;
            return;
        }
    }
    wcout << RED << L"Số phòng không tồn tại!\n" << RESET;
}
