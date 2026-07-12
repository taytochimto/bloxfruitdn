#include "CheckOut.h"
#include <sstream>
#include <cstdio>   
#include <fcntl.h>  
#include <io.h>     


int nhapSoAnToanCO() {
    wstring line;
    while (true) {
        getline(wcin, line);
        if (line.empty()) continue; 
        try {
            return stoi(line); 
        } catch (...) {
            wcout << RED << L"Lỗi! Vui lòng chỉ nhập SỐ: " << RESET;
        }
    }
}


void checkOut(vector<Phong>& dsPhong) {
    wcout << L"Nhập số phòng muốn Check-out: ";
    int soPhong = nhapSoAnToanCO(); 

    for (auto& phong : dsPhong) {
        if (phong.soPhong == soPhong) {
            if (!phong.daDat) {
                wcout << RED << L"Phòng này hiện đang trống, không thể Check-out!\n" << RESET;
                return;
            }
            
            long long tongTien = (phong.giaPhong * phong.soNgayO) + phong.tienDichVu;
            
            wcout << CYAN << L"\n=========================================\n" << RESET;
            wcout << CYAN << L"           HÓA ĐƠN THANH TOÁN            \n" << RESET;
            wcout << CYAN << L"=========================================\n" << RESET;
            wcout << L"Khách hàng   : " << phong.khach.ten << L"\n";
            wcout << L"Số phòng     : " << phong.soPhong << L" (" << phong.loaiPhong << L")\n";
            wcout << L"Số ngày ở    : " << phong.soNgayO << L"\n";
            wcout << L"Giá phòng    : " << phong.giaPhong << L" VNĐ/ngày\n";
            wcout << L"Tiền dịch vụ : " << phong.tienDichVu << L" VNĐ\n";
            wcout << YELLOW << L"TỔNG CỘNG    : " << tongTien << L" VNĐ\n" << RESET;
            wcout << CYAN << L"=========================================\n\n" << RESET;
            
            phong.daDat = false;
            phong.khach.ten = L"None";
            phong.khach.cccd = L"None";
            phong.khach.sdt = L"None";
            phong.tienDichVu = 0;
            phong.soNgayO = 0;
            
            wcout << GREEN << L"Check-out thành công! Phòng đã được dọn sạch.\n" << RESET;
            return;
        }
    }
    wcout << RED << L"Không tìm thấy số phòng này trong hệ thống!\n" << RESET;
}


void ghiFile(const vector<Phong>& dsPhong, const string& filename) {
   
    FILE* f = fopen(filename.c_str(), "w");
    
    if (f == NULL) {
        wcout << RED << L"Lỗi: Không thể mở file để ghi!\n" << RESET;
        return;
    }
    
    
    _setmode(_fileno(f), _O_U8TEXT);
    
    int dem = 0;
    for (const auto& p : dsPhong) {
        
        fwprintf(f, L"%d,%ls,%d,%d,%ls,%ls,%ls,%d,%d\n",
                 p.soPhong, 
                 p.loaiPhong.c_str(), 
                 (int)p.giaPhong, 
                 (int)p.daDat,
                 (p.daDat ? p.khach.ten.c_str() : L"None"),
                 (p.daDat ? p.khach.cccd.c_str() : L"None"),
                 (p.daDat ? p.khach.sdt.c_str() : L"None"),
                 (int)p.tienDichVu, 
                 (int)p.soNgayO);
        dem++;
    }
    
    fclose(f);
    wcout << GREEN << L"Đã lưu thành công " << dem << L" phòng vào đĩa cứng (Đã khắc phục lỗi Dev-C++).\n" << RESET;
}


void docFile(vector<Phong>& dsPhong, const string& filename) {
    FILE* f = fopen(filename.c_str(), "r");
    
    if (f == NULL) {
        wcout << YELLOW << L"Chưa có file dữ liệu cũ. Hệ thống sẽ dùng dữ liệu mặc định.\n" << RESET;
        dsPhong.push_back({101, L"Thuong", 300000, false, {L"None", L"None", L"None"}, 0, 0});
        dsPhong.push_back({102, L"VIP", 600000, false, {L"None", L"None", L"None"}, 0, 0});
        dsPhong.push_back({201, L"VIP", 600000, false, {L"None", L"None", L"None"}, 0, 0});
        return;
    }

    _setmode(_fileno(f), _O_U8TEXT);
    dsPhong.clear();
    
    wchar_t buffer[2048];
    while (fgetws(buffer, 2048, f)) {
        wstring line(buffer);
        
        
        if (!line.empty() && line.back() == L'\n') line.pop_back();
        if (!line.empty() && line.back() == L'\r') line.pop_back();
        if (line.empty()) continue;
        
        wstringstream ss(line);
        wstring token;
        Phong p;
        
        try {
            getline(ss, token, L','); p.soPhong = stoi(token);
            getline(ss, p.loaiPhong, L','); 
            getline(ss, token, L','); p.giaPhong = stoi(token);
            getline(ss, token, L','); p.daDat = (token == L"1");
            
            getline(ss, p.khach.ten, L',');
            getline(ss, p.khach.cccd, L',');
            getline(ss, p.khach.sdt, L',');
            
            getline(ss, token, L','); p.tienDichVu = stoi(token);
            getline(ss, token, L','); p.soNgayO = stoi(token);
            
            dsPhong.push_back(p);
        } catch (...) {
            continue;
        }
    }
    
    fclose(f);
    wcout << GREEN << L"Nạp dữ liệu từ file thành công!\n" << RESET;
}
