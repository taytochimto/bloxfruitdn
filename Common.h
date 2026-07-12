#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

using namespace std;


const wstring RESET   = L"\033[0m";
const wstring RED     = L"\033[31m";
const wstring GREEN   = L"\033[32m";
const wstring YELLOW  = L"\033[33m";
const wstring CYAN    = L"\033[36m";


struct KhachHang {
    wstring ten = L"";
    wstring cccd = L"";
    wstring sdt = L"";
};

struct Phong {
    int soPhong;
    wstring loaiPhong; 
    double giaPhong;
    bool daDat = false;
    KhachHang khach;
    double tienDichVu = 0.0;
    int soNgayO = 0;
};
