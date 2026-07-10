#include "Menu.h"

void hienThiMenu() {
    wcout << CYAN << L"\n╔═════════════════════════════════════════════╗\n";
    wcout << L"║       HỆ THỐNG QUẢN LÝ KHÁCH SẠN C++        ║\n";
    wcout << L"╠═════════════════════════════════════════════╣\n" << RESET;
    wcout << L"║ " << YELLOW << L"1." << RESET << L" Hiển thị sơ đồ phòng (Chi tiết)         ║\n";
    wcout << L"║ " << YELLOW << L"2." << RESET << L" Check-in (Nhận phòng mới)               ║\n";
    wcout << L"║ " << YELLOW << L"3." << RESET << L" Gọi dịch vụ (Đồ ăn, giặt là...)         ║\n";
    wcout << L"║ " << YELLOW << L"4." << RESET << L" Tìm kiếm khách hàng (Theo CCCD)         ║\n";
    wcout << L"║ " << YELLOW << L"5." << RESET << L" Check-out (Trả phòng & In hóa đơn)      ║\n";
    wcout << L"║ " << YELLOW << L"6." << RESET << L" Lưu dữ liệu thủ công xuống file         ║\n";
    wcout << L"║ " << RED    << L"0." << RESET << L" Thoát chương trình (Tự động lưu)        ║\n";
    wcout << CYAN << L"╚═════════════════════════════════════════════╝\n" << RESET;
    wcout << L"👉 Nhập lựa chọn của bạn: ";
}

void hienThiSoDoPhong(const vector<Phong>& dsPhong) {
    wcout << YELLOW << L"\n                  --- SƠ ĐỒ PHÒNG KHÁCH SẠN ---                  \n\n" << RESET;
    
    for (size_t i = 0; i < dsPhong.size(); i++) {
        // Rút gọn giá tiền (VD: 200000 -> 200k) cho đẹp sơ đồ
        wstring giaTien = to_wstring((int)(dsPhong[i].giaPhong / 1000)) + L"k";

        if (dsPhong[i].daDat) {
            wcout << RED << L"[ P." << dsPhong[i].soPhong << L" | " << dsPhong[i].loaiPhong << L" | " << giaTien << L" ] - Đã Đặt   " << RESET;
        } else {
            wcout << GREEN << L"[ P." << dsPhong[i].soPhong << L" | " << dsPhong[i].loaiPhong << L" | " << giaTien << L" ] - Trống    " << RESET;
        }
        
        // Vì thông tin dài ra, nên 3 phòng sẽ xuống dòng 1 lần cho vừa màn hình
        if ((i + 1) % 3 == 0) {
            wcout << L"\n\n";
        }
    }
    
    wcout << L"\n";
    wcout << CYAN << L"-----------------------------------------------------------------\n" << RESET;
    wcout << L"Chú thích: " << GREEN << L"Màu xanh (Đang trống)" << RESET << L" | " << RED << L"Màu đỏ (Đang có khách)" << RESET << L"\n";
}
