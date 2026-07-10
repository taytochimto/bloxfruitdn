#include "Menu.h"

void hienThiMenu() {
    wcout << CYAN << L"\n=========================================\n";
    wcout << L"    HỆ THỐNG QUẢN LÝ KHÁCH SẠN C++\n";
    wcout << L"=========================================\n" << RESET;
    wcout << L"1. Hiển thị sơ đồ phòng (Lưới)\n";
    wcout << L"2. Check-in (Đặt phòng)\n";
    wcout << L"3. Gọi dịch vụ (Đồ ăn, thức uống)\n";
    wcout << L"4. Tìm kiếm khách hàng theo CCCD\n";
    wcout << L"5. Check-out & In hóa đơn\n";
    wcout << L"6. Lưu dữ liệu thủ công\n";
    wcout << L"0. Thoát và tự động lưu\n";
    wcout << CYAN << L"-----------------------------------------\n" << RESET;
    wcout << L"Nhập lựa chọn của bạn: ";
}

void hienThiSoDoPhong(const vector<Phong>& dsPhong) {
    wcout << L"\n--- SƠ ĐỒ PHÒNG KHÁCH SẠN ---\n";
    for (size_t i = 0; i < dsPhong.size(); i++) {
        if (dsPhong[i].daDat) {
            wcout << RED << L"[P." << dsPhong[i].soPhong << L" X] " << RESET; // Phòng có khách (Đỏ)
        } else {
            wcout << GREEN << L"[P." << dsPhong[i].soPhong << L" R] " << RESET; // Phòng trống (Xanh)
        }
        if ((i + 1) % 5 == 0) wcout << L"\n"; // Cứ 5 phòng thì xuống dòng tạo dạng lưới
    }
    wcout << L"\nChú thích: " << GREEN << L"[R]: Trống" << RESET << L" | " << RED << L"[X]: Đã đặt" << RESET << L"\n";
}
