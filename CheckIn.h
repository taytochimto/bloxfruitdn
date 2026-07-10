#pragma once
#include "Common.h"
#include <cwctype>
wstring nhapTenSafe();
wstring nhapSDTSafe(const vector<Phong>& dsPhong);
wstring nhapCCCDSafe(const vector<Phong>& dsPhong);
int nhapSoNguyenSafe();
void checkIn(vector<Phong>& dsPhong);

