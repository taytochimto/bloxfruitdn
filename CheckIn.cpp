#include "CheckIn.h"

int nhapSoNguyenSafe() {
    int value;
    while (true) {
        if (wcin >> value) {
            wcin.ignore(10000, L'\n'); // Xóa bộ nhớ đệm sau khi nhập đúng
            return value;
        } else {
            wcin.clear(); // Xóa cờ lỗi
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
            
            wcout << L"Nhập tên khách hàng: ";
            // Kỹ thuật wcin >> ws: Hút sạch dấu Enter thừa ở dòng trước
            getline(wcin >> ws, phong.khach.ten);
            
            wcout << L"Nhập CCCD: ";
            getline(wcin, phong.khach.cccd);
            
            wcout << L"Nhập Số Điện Thoại: ";
            getline(wcin, phong.khach.sdt);
            
            wcout << L"Nhập số ngày dự kiến ở: ";
            phong.soNgayO = nhapSoNguyenSafe();

            phong.daDat = true;
            wcout << GREEN << L"Check-in phòng " << soPhong << L" thành công!\n" << RESET;
            return;
        }
    }
    wcout << RED << L"Số phòng không tồn tại!\n" << RESET;
}
