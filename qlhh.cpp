#include<bits/stdc++.h>
using namespace std;
class hang {
public:
    int id;
    string ten;
    long long gia;
    int sl;
    hang() : id(0), ten(""), gia(0), sl(0) {}
    hang(int _id, const string& _ten, long long _gia, int _sl)
        : id(_id), ten(_ten), gia(_gia), sl(_sl) {}
};
const int MAX_HANG = 200;
void them_hang(hang kho_h[], int &n, const hang& hangmoi)
{
    for (int i = 0; i < n; ++i) {
        if (kho_h[i].id == hangmoi.id) {
            kho_h[i].ten = hangmoi.ten;
            kho_h[i].gia = hangmoi.gia;
            kho_h[i].sl += hangmoi.sl;
            cout << "ID TRUNG.DA CAP NHAT HANG CONG DON SL.ID=" << hangmoi.id << "\n";
            return;
        }
    }
    if (n < MAX_HANG) {
        kho_h[n] = hangmoi;
        ++n;
        cout << "DA THEM HANG MOI: ID=" << hangmoi.id << " TEN='" << hangmoi.ten << "'\n";
    } else {
        cout << "LOI: KHO DA DAY, KHONG THE THEM.\n";
    }
}
void hien_tong(hang kho_h[], int n) {
    long long tong_sl = 0;
    long long tong_giatri = 0;
    for (int i = 0; i < n; ++i) {
        tong_sl += kho_h[i].sl;
        tong_giatri += kho_h[i].gia * (long long)kho_h[i].sl;
    }
    cout << "TONG SO LUONG HANG HOA HIEN TAI: " << tong_sl << "\n";
    cout << "TONG GIA TRI KHO HIEN TAI: " << tong_giatri << "\n";
}
bool nhap_int(const string& thongbao, int& out) {
    while (1) {
        cout << thongbao;
        if (cin >> out) {
            return 1;
        }
        if (cin.eof()) return 0;
        cin.clear();
        string dmy;
        getline(cin, dmy);
        cout << "GIA TRI KHONG HOP LE.THU LAI.\n";
    }
}
bool nhap_longlong(const string& thongbao, long long& out) {
    while (1) {
        cout << thongbao;
        if (cin >> out) {
            return 1;
        }
        if (cin.eof()) return 0;
        cin.clear();
        string dmy;
        getline(cin, dmy);
        cout << "GIA TRI KHONG HOP LE (YEU CAU SO NGUYEN).THU LAI.\n";
    }
}
int main() {
    hang kho_h[MAX_HANG];
    int n = 0;
    while (true) {
        cout << "\n-HE THONG QUAN LY HANG HOA-\n";
        cout << "1. NHAP HANG MOI / BO SUNG\n";
        cout << "2. HIEN THI TOAN BO KHO\n";
        cout << "0. THOAT\n";
        int chon;
        if (!nhap_int("CHON (0/1/2): ", chon)) break;
        if (chon == 0) break;
        if (chon == 1) {
            int id;
            if (!nhap_int("NHAP ID (SO NGUYEN): ", id)) break;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "NHAP TEN: ";
            string ten;
            getline(cin, ten);
            long long gia;
            if (!nhap_longlong("NHAP GIA BAN (SO NGUYEN): ", gia)) break;
            int sl;
            if (!nhap_int("NHAP SO LUONG: ", sl)) break;
            if (sl < 0) {
                cout << "SO LUONG PHAI >= 0.BO QUA NHAP NAY.\n";
                continue;
            }
            hang h(id, ten, gia, sl);
            them_hang(kho_h, n, h);
            hien_tong(kho_h, n);
        } else if (chon == 2) {
            if (n == 0) {
                cout << "KHO RONG.\n";
            } else {
                cout << "\nDANH SACH HANG HOA:\n";
                for (int i = 0; i < n; ++i) {
                    cout << "ID=" << kho_h[i].id << " | TEN='" << kho_h[i].ten << "' | GIA=" << kho_h[i].gia
                              << " | SO LUONG=" << kho_h[i].sl << " | GIA TRI=" << (kho_h[i].gia * (long long)kho_h[i].sl) << "\n";
                }
                hien_tong(kho_h, n);
            }
        } else {
            cout << "LUA CHON KHONG HOP LE.THU LAI.\n";
        }
    }
    cout << "KET THUC CHUONG TRINH.\n";
}
