#include "CheckIn.h"
#include <cwctype>
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
wstring nhapTenSafe() {
    wstring input;
    while (true) {
        getline(wcin >> ws, input);
        bool coChuaSo = false;
        
        // Quét từng ký tự xem người dùng có gõ số vào tên không
        for (wchar_t c : input) {
            if (iswdigit(c)) { 
                coChuaSo = true;
                break;
            }
        }
        
        if (!coChuaSo && !input.empty()) {
            return input; // Hợp lệ thì trả về tên
        } else {
            // Lưu ý: Nếu bạn có định nghĩa màu (như RED, RESET), hãy thêm vào đây
            wcout << L"Lỗi! Tên không được chứa số hoặc để trống. Vui lòng nhập lại: ";
        }
    }
}
wstring nhapChuoiSoSafe() {
    wstring input;
    while (true) {
        getline(wcin >> ws, input);
        bool toanLaSo = true;
        
        // Quét từng ký tự, nếu có ký tự nào không phải là số -> Lỗi
        for (wchar_t c : input) {
            if (!iswdigit(c)) {
                toanLaSo = false;
                break;
            }
        }
        
        if (toanLaSo && !input.empty()) {
            return input; // Hợp lệ thì trả về chuỗi số
        } else {
            wcout << L"Lỗi! Dữ liệu này chỉ được chứa số. Vui lòng nhập lại: ";
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
            wcin.clear();
			wcin.ignore(10000, L'\n');
            // Bây giờ bộ nhớ đã sạch 100%, cứ dùng getline bình thường
            wcout << L"Nhập tên khách hàng : " ;
            phong.khach.ten = nhapTenSafe();
            
            wcout << L"Nhập số CCCD: ";
            phong.khach.cccd = nhapChuoiSoSafe();
            
            wcout << L"Nhập Số Điện Thoại: ";
            phong.khach.sdt = nhapChuoiSoSafe();
            
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
