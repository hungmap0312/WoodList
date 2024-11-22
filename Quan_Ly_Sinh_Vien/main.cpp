#include <iostream>
#include <string>
using namespace std;

struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    int maSV;
    string hoTen;
    int gioiTinh;
    Ngay ngaySinh;
    string diaChi;
    string lop;
    string khoa;
};

struct Node {
    SinhVien data;
    Node *link;
};

Node* createNode(int maSV, string hoTen, int gioiTinh, int ngay, int thang, int nam, string diaChi, string lop, string khoa) {
    Node *temp = new Node;
    temp->link = NULL;
    temp->data.maSV = maSV;
    temp->data.hoTen = hoTen;
    temp->data.gioiTinh = gioiTinh;
    temp->data.ngaySinh.ngay = ngay;
    temp->data.ngaySinh.thang = thang;
    temp->data.ngaySinh.nam = nam;
    temp->data.diaChi = diaChi;
    temp->data.lop = lop;
    temp->data.khoa = khoa;
    return temp;
}

Node* addElement(Node* p, int maSV, string hoTen, int gioiTinh, int ngay, int thang, int nam, string diaChi, string lop, string khoa) {
    Node *temp = createNode(maSV, hoTen, gioiTinh, ngay, thang, nam, diaChi, lop, khoa);
    p->link = temp;
    return temp;
}

int main() {
    int soLuongSV;
    cout << "Nhap so luong sinh vien muon them: ";
    cin >> soLuongSV;
    cin.ignore();

    Node* ListSV = nullptr;
    Node* p = nullptr;

    for (int i = 1; i <= soLuongSV; i++) {
        int maSV, gioiTinh;
        string hoTen, diaChi, lop, khoa;
        Ngay ngaySinh;

        cout << "\nNhap ma so sinh vien so " << i << ": ";
        cin >> maSV;
        cin.ignore();

        cout << "Nhap ho ten sinh vien so " << i << ": ";
        getline(cin, hoTen);

        cout << "Nhap gioi tinh sinh vien so " << i << ": ";
        cin >> gioiTinh;
        cin.ignore();

        cout << "Nhap ngay sinh sinh vien so " << i << ": ";
        cin >> ngaySinh.ngay;
        cin.ignore();

        cout << "Nhap thang sinh sinh vien so " << i << ": ";
        cin >> ngaySinh.thang;
        cin.ignore();

        cout << "Nhap nam sinh sinh vien so " << i << ": ";
        cin >> ngaySinh.nam;
        cin.ignore();

        cout << "Nhap dia chi sinh vien so " << i << ": ";
        getline(cin, diaChi);

        cout << "Nhap lop sinh vien so " << i << ": ";
        getline(cin, lop);

        cout << "Nhap khoa sinh vien so " << i << ": ";
        getline(cin, khoa);

        if (ListSV == nullptr) {
            ListSV = createNode(maSV, hoTen, gioiTinh, ngaySinh.ngay, ngaySinh.thang, ngaySinh.nam, diaChi, lop, khoa);
            p = ListSV;
        } else {
            p = addElement(p, maSV, hoTen, gioiTinh, ngaySinh.ngay, ngaySinh.thang, ngaySinh.nam, diaChi, lop, khoa);
        }
    }

    cout << "Hello world!" << endl;
    return 0;
}
