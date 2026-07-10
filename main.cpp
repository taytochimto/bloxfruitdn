#include "Common.h"
#include "Menu.h"
#include "CheckIn.h"
#include "DichVu.h"
#include "CheckOut.h"

// Tạo danh sách phòng mặc định nếu mở app lần đầu
void khoiTaoPhongMacDinh(vector<Phong>& dsPhong) {
    dsPhong.push_back({101, L"Đơn", 200000});
    dsPhong.push_back({102, L"Đơn", 200000});
    dsPhong.push_back({103, L"Đôi", 350000});
    dsPhong.push_back({201, L"Đôi", 350000});
    dsPhong.push_back({202, L"VIP", 600000});
}

int main() {
    // Ép Console sang tiếng Việt
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    vector<Phong> dsPhong;
    
    // Nạp dữ liệu cũ (Người 4)
    docFile(dsPhong, "data.txt");
    if (dsPhong.empty()) {
        khoiTaoPhongMacDinh(dsPhong);
    }

    int luaChon;
    do {
        hienThiMenu(); // (Người 1)
        luaChon = nhapSoNguyenSafe(); // (Người 3)

        switch (luaChon) {
            case 1: hienThiSoDoPhong(dsPhong); break;         // (Người 1)
            case 2: checkIn(dsPhong); break;                  // (Người 3)
            case 3: goiDichVu(dsPhong); break;                // (Người 2)
            case 4: timKiemKhachHang(dsPhong); break;         // (Người 2)
            case 5: checkOut(dsPhong); break;                 // (Người 4)
            case 6: ghiFile(dsPhong, "data.txt"); break;      // (Người 4)
            case 0:
                ghiFile(dsPhong, "data.txt");
                wcout << L"Cảm ơn bạn đã sử dụng phần mềm!\n";
                break;
            default:
                wcout << RED << L"Lựa chọn không hợp lệ!\n" << RESET;
        }
    } while (luaChon != 0);

    return 0;
}
