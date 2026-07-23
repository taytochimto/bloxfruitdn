#include "DichVu.h"

void goiDichVu(vector<Phong>& dsPhong) {
    int soPhong;
    wcout << L"Nhập số phòng muốn gọi dịch vụ: ";
    wcin >> soPhong;

    for (auto& phong : dsPhong) {
        if (phong.soPhong == soPhong) {
            if (!phong.daDat) {
                wcout << RED << L"Phòng này đang trống, không thể gọi dịch vụ!\n" << RESET;
                return;
            }
            int chon;
            do {
                wcout << L"\n--- MENU DỊCH VỤ (Phòng " << phong.soPhong << L") ---\n";
                wcout << L"1. Nước uống (20.000đ)\n";
                wcout << L"2. Đồ ăn nhanh (50.000đ)\n";
                wcout << L"3. Giặt là (30.000đ)\n";
                wcout << L"0. Hoàn thành / Quay lại\n";
                wcout << L"Lựa chọn của bạn: ";
                wcin >> chon;
                if (chon == 1) { 
                    phong.tienDichVu += 20000; 
                    wcout << L"-> Đã thêm Nước uống (20.000đ).\n"; 
                }
                else if (chon == 2) { 
                    phong.tienDichVu += 50000; 
                    wcout << L"-> Đã thêm Đồ ăn nhanh (50.000đ).\n"; 
                }
                else if (chon == 3) { 
                    phong.tienDichVu += 30000; 
                    wcout << L"-> Đã thêm Giặt là (30.000đ).\n"; 
                }
                else if (chon == 0) {
                    wcout << L"-> Hoàn tất chọn dịch vụ.\n";
                }
                else {
                    wcout << RED << L"Lựa chọn không hợp lệ. Vui lòng thử lại!\n" << RESET;
                }
            } while (chon != 0);

            return;
        }
    }

    wcout << RED << L"Không tìm thấy số phòng này!\n" << RESET;
}

void timKiemKhachHang(const vector<Phong>& dsPhong) {
    wstring cccd;
    wcout << L"Nhập số CCCD của khách hàng cần tìm: ";
    wcin >> cccd;

    for (const auto& phong : dsPhong) {
        if (phong.daDat && phong.khach.cccd == cccd) {
            wcout << GREEN << L"\nTìm thấy khách hàng: " << phong.khach.ten << RESET << L"\n";
            wcout << L"- Đang ở phòng: " << phong.soPhong << L" (" << phong.loaiPhong << L")\n";
            wcout << L"- Số ĐT: " << phong.khach.sdt << L"\n";
            return; // Đã tìm thấy khách hàng, kết thúc tìm kiếm
        }
    }

    wcout << RED << L"Không tìm thấy khách hàng có CCCD trên!\n" << RESET;
}
    wcout << RED << L"Không tìm thấy khách hàng có CCCD trên!\n" << RESET;
}
