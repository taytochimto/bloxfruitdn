#include "CheckIn.h"
#include <cwctype>

int nhapSoNguyenSafe() {
    int value;
    wstring chuoiTam; 
    
    while (true) {
        if (wcin >> value) {
            
            getline(wcin, chuoiTam); 
            return value;
        } else {
           
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
        
        
        for (wchar_t c : input) {
            if (iswdigit(c)) { 
                coChuaSo = true;
                break;
            }
        }
        
        if (!coChuaSo && !input.empty()) {
            return input; 
        } else {
           
            wcout << RED << L"Lỗi! Tên không được chứa số hoặc để trống. Vui lòng nhập lại: " << RESET;
        }
    }
}
wstring nhapCCCDSafe(const vector<Phong>& dsPhong) {
    wstring input;
    while (true) {
        getline(wcin >> ws, input);
        
        
        bool toanLaSo = true;
        for (wchar_t c : input) {
            if (!iswdigit(c)) {
                toanLaSo = false;
                break;
            }
        }
        if (!toanLaSo || input.empty()) {
            wcout << RED << L"Lỗi! CCCD chỉ được chứa số. Vui lòng nhập lại: " << RESET;
            continue; 
        }

        
        if (input.length() != 12) {
            wcout << RED << L"Lỗi! Số CCCD phải có ĐÚNG 12 chữ số. Vui lòng nhập lại: " << RESET;
            continue;
        }

        
        bool biTrung = false;
        for (const auto& phong : dsPhong) {
            if (phong.daDat && phong.khach.cccd == input) {
                biTrung = true;
                break;
            }
        }
        if (biTrung) {
            wcout << RED << L"Lỗi! Số CCCD này đã được đăng ký ở phòng khác. Vui lòng nhập lại: " << RESET;
            continue;
        }

        return input; 
    }
}
wstring nhapSDTSafe(const vector<Phong>& dsPhong) {
    wstring input;
    while (true) {
        getline(wcin >> ws, input);
        
       
        bool toanLaSo = true;
        for (wchar_t c : input) {
            if (!iswdigit(c)) {
                toanLaSo = false;
                break;
            }
        }
        if (!toanLaSo || input.empty()) {
            wcout << RED << L"Lỗi! Số điện thoại chỉ được chứa số. Vui lòng nhập lại: " << RESET;
            continue;
        }

        
        if (input.length() != 10 || input[0] != L'0') {
            wcout << RED << L"Lỗi! SĐT phải có ĐÚNG 10 chữ số và bắt đầu bằng số 0. Vui lòng nhập lại: " << RESET;
            continue;
        }

        
        bool biTrung = false;
        for (const auto& phong : dsPhong) {
            if (phong.daDat && phong.khach.sdt == input) {
                biTrung = true;
                break;
            }
        }
        if (biTrung) {
            wcout << RED << L"Lỗi! Số điện thoại này đã được đăng ký ở phòng khác. Vui lòng nhập lại: " << RESET;
            continue;
        }

        return input; 
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
            
            wcout << L"Nhập tên khách hàng : " ;
            phong.khach.ten = nhapTenSafe();
            
            wcout << L"Nhập số CCCD: ";
            phong.khach.cccd = nhapCCCDSafe(dsPhong);
            
            wcout << L"Nhập Số Điện Thoại: ";
            phong.khach.sdt = nhapSDTSafe(dsPhong);
            
            wcout << L"Nhập số ngày dự kiến ở: ";
            phong.soNgayO = nhapSoNguyenSafe();

            
            phong.daDat = true;
            wcout << GREEN << L"Check-in phòng " << soPhong << L" thành công!\n" << RESET;
            return;
        }
    }
    wcout << RED << L"Số phòng không tồn tại!\n" << RESET;
}
