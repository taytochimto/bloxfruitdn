#include "CheckIn.h"

// Hàm này đã được sửa lại: Dùng chuỗi tạm để dọn rác thay vì wcin.ignore()
int nhapSoNguyenSafe() {
    int value;
    wstring chuoiTam; // Tạo một chuỗi rỗng làm thùng rác
    
    while (true) {
        if (wcin >> value) {
            // Đọc số thành công -> Hút luôn phím Enter đang kẹt ném vào thùng rác
            getline(wcin, chuoiTam); 
            return value;
        } else {
            // Đọc thất bại (người dùng nhập chữ) -> Xóa cờ lỗi và dọn sạch thùng rác
            wcin.clear(); 
            getline(wcin, chuoiTam);
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
            wcin.ignore();
            // Bây giờ bộ nhớ đã sạch 100%, cứ dùng getline bình thường
            wcout << L"Nhập tên khách hàng (VD: Nguyễn Văn A): " ;
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
