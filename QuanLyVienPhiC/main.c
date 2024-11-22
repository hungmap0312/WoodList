#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAX_VIEN_PHI 100

struct VienPhi {
    char code[4];       //Mã viện phí
    char name[50];      //Tên viện phí
    unsigned long fee;  //Giá viện phí
};

void menu() {           //Hàm hiển thị các chức năng của chương trình
    system("cls");
    printf("1. Tao vien phi\n");
    printf("2. Hien thi vien phi\n");
    printf("3. Sua vien phi\n");
    printf("4. Xoa vien phi\n");
    printf("5. Sap xep vien phi\n");
    printf("6. Tim kiem vien phi\n");
    printf("7. In hoa don vien phi\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon: ");
}

/*
void menu();
void readFromFile(struct VienPhi, int*);
void writeToFile(const struct VienPhi, int);
int kiemTraMaVienPhi(const char);
int kiemTraTrungMa(const struct VienPhi, int, const char);
void add(struct VienPhi, int*);
void display(const struct VienPhi, int);
void modify(struct VienPhi, int);
void deleteVP(struct VienPhi, int*);
void arrange(struct VienPhi, int);
void findVP(const struct VienPhi, int);
void calculateInvoice(const struct VienPhi, int);
int exitVP(const struct VienPhi, int);
*/

void readFromFile(struct VienPhi dsVienPhi[], int *numVienPhi) {    //Hàm đọc dữ liệu từ file "vienphi.data"
    FILE *file = fopen("vienphi.dat", "r");
    if (!file) {
        printf("Khong the mo file vienphi.dat!\n");
        return;
    }
    *numVienPhi = 0; // Khởi tạo số lượng viện phí là 0.
    while (fscanf(file, "%3s %[^\n] %lu", dsVienPhi[*numVienPhi].code, dsVienPhi[*numVienPhi].name, &dsVienPhi[*numVienPhi].fee) == 3) {
        (*numVienPhi)++;
    }
    fclose(file);
}

void writeToFile(const struct VienPhi dsVienPhi[], int numVienPhi) {    //Hàm ghi dữ liệu vào file "vienphi.data"
    FILE *file = fopen("vienphi.dat", "w");
    if (!file) {
        printf("Khong the mo file vienphi.dat de ghi!\n");
        return;
    }
    for (int i = 0; i < numVienPhi; ++i) {
        fprintf(file, "%s\n%s\n%lu\n", dsVienPhi[i].code, dsVienPhi[i].name, dsVienPhi[i].fee);
    }
    fclose(file);
}

int kiemTraMaVienPhi(const char code[]) {       //Hàm kiểm tra tính hợp lệ của mã viện phí vừa nhập
    if (strlen(code) != 3)      //Kiểm tra độ dài của mã
        return 0;       //Mã không hợp lệ
    if (code[0] != 'T' && code[0] != 'D' && code[0] != 'P')     //Kiểm tra ký tự đầu tiên của mã
        return 0;       //Mã không hợp lệ
    for (int i = 1; i < 3; ++i) {       //Kiểm tra 2 ký tự tiếp theo
        if (!isdigit(code[i]))
            return 0;   //Mã không hợp lệ
    }
    return 1;       //Mã hợp lệ
}

int kiemTraTrungMa(const struct VienPhi dsVienPhi[], int numVienPhi, const char code[]) {       //Hàm kiểm tra trùng lặp của mã viện phí vừa nhập
    for (int i = 0; i < numVienPhi; i++) {
        if (strcmp(dsVienPhi[i].code, code) == 0) {
            return 1; // Mã đã tồn tại
        }
    }
    return 0; // Mã chưa tồn tại
}

void add(struct VienPhi dsVienPhi[], int *numVienPhi) {     //Hàm nhập vào n viên phí mới
    int n;
    while (1) {
        printf("Nhap so luong vien phi can them: ");
        if (scanf("%d", &n) != 1 || n <= 0) {       //Kiểm tra ký tự vừa nhập có phải số nguyên dương
            printf("Loi: Ban phai nhap mot so nguyen duong. Vui long thu lai.\n");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        struct VienPhi vp;
        do {
            printf("Nhap ma vien phi: ");
            scanf("%3s", vp.code);
            if (!kiemTraMaVienPhi(vp.code)) {                           //Kiểm tra tính hợp lệ của mã
                printf("Ma vien phi khong hop le. Vui long nhap lai.\n");
                continue;
            }
            if (kiemTraTrungMa(dsVienPhi, *numVienPhi, vp.code)) {      //Kiểm tra trùng mã
                printf("Ma vien phi da ton tai. Vui long nhap lai.\n");
                continue;
            }
            break;
        } while (1);
        printf("Nhap ten vien phi: ");
        getchar();
        fgets(vp.name, sizeof(vp.name), stdin);
        vp.name[strcspn(vp.name, "\n")] = '\0';
        while (1) {
            printf("Nhap gia vien phi: ");
            if (scanf("%lu", &vp.fee) != 1 || vp.fee <= 0) {
                printf("Loi: Ban phai nhap mot so nguyen duong. Vui long thu lai.\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        }
        dsVienPhi[*numVienPhi] = vp;
        (*numVienPhi)++;
    }
}

void display(const struct VienPhi dsVienPhi[], int numVienPhi) {        //Hàm hiển thị các viện phí
    for (int i = 0; i < numVienPhi; ++i) {
        printf("Ma: %s, Ten: %s, Gia: %lu\n", dsVienPhi[i].code, dsVienPhi[i].name, dsVienPhi[i].fee);
    }
}

void modify(struct VienPhi dsVienPhi[], int numVienPhi) {               //Hàm sửa một viện phí
    char code[4];
    printf("Nhap ma vien phi can sua: ");
    scanf("%3s", code);
    int found = 0;
    for (int i = 0; i < numVienPhi; ++i) {
        if (strcmp(dsVienPhi[i].code, code) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Nhap ten vien phi moi: ");
            getchar();
            fgets(dsVienPhi[i].name, sizeof(dsVienPhi[i].name), stdin);
            dsVienPhi[i].name[strcspn(dsVienPhi[i].name, "\n")] = '\0';
            while (1) {
                printf("Nhap gia vien phi moi: ");
                if (scanf("%lu", &dsVienPhi[i].fee) != 1 || dsVienPhi[i].fee <= 0) {
                    printf("Loi: Ban phai nhap mot so nguyen duong. Vui long thu lai.\n");
                    while (getchar() != '\n');
                }
                else {
                    break;
                }
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ma vien phi!\n");
    }
}

void deleteVP(struct VienPhi dsVienPhi[], int *numVienPhi) {            //Hàm xóa một viện phí
    char code[4];
    printf("Nhap ma vien phi can xoa: ");
    scanf("%3s", code);
    int found = 0;
    for (int i = 0; i < *numVienPhi; ++i) {
        if (strcmp(dsVienPhi[i].code, code) == 0) {
            for (int j = i; j < *numVienPhi - 1; ++j) {
                dsVienPhi[j] = dsVienPhi[j + 1];
            }
            (*numVienPhi)--;
            found = 1;
            printf("Xoa thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ma vien phi!\n");
    }
}

void arrange(struct VienPhi dsVienPhi[], int numVienPhi) {          //Hàm sắp xếp viện phí theo mã/tên/giá
    int choice;
    printf("1. Sap xep theo ma\n");
    printf("2. Sap xep theo ten\n");
    printf("3. Sap xep theo gia\n");
    printf("Nhap lua chon: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Nhap khong hop le!\n");
        while (getchar() != '\n');
        return;
        printf("Enter any key to continue...");
        getch();
    }
    switch (choice) {
        case 1:
            for (int i = 0; i < numVienPhi - 1; ++i) {
                for (int j = i + 1; j < numVienPhi; ++j) {
                    if (strcmp(dsVienPhi[i].code, dsVienPhi[j].code) > 0) {
                        struct VienPhi temp = dsVienPhi[i];
                        dsVienPhi[i] = dsVienPhi[j];
                        dsVienPhi[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < numVienPhi - 1; ++i) {
                for (int j = i + 1; j < numVienPhi; ++j) {
                    if (strcmp(dsVienPhi[i].name, dsVienPhi[j].name) > 0) {
                        struct VienPhi temp = dsVienPhi[i];
                        dsVienPhi[i] = dsVienPhi[j];
                        dsVienPhi[j] = temp;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < numVienPhi - 1; ++i) {
                for (int j = i + 1; j < numVienPhi; ++j) {
                    if (dsVienPhi[i].fee > dsVienPhi[j].fee) {
                        struct VienPhi temp = dsVienPhi[i];
                        dsVienPhi[i] = dsVienPhi[j];
                        dsVienPhi[j] = temp;
                    }
                }
            }
            break;
    }
}

void findVP(const struct VienPhi dsVienPhi[], int numVienPhi) {         //Hàm tìm kiếm một viện phí bằng mã/tên
    int choice;
    printf("1. Tim kiem bang ma\n");
    printf("2. Tim kiem bang ten\n");
    printf("Nhap lua chon: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
        printf("Nhap khong hop le!\n");
        while (getchar() != '\n');
        return;
        printf("Enter any key to continue...");
        getch();
    }
    int found = 0;
    char code[4];
    char name[50];
    switch (choice) {
        case 1:
            printf("Nhap ma vien phi muon tim kiem: ");
            scanf("%3s", code);
            for (int i = 0; i < numVienPhi; ++i) {
                if (strcmp(dsVienPhi[i].code, code) == 0) {
                    printf("Ma: %s, Ten: %s, Gia: %lu\n", dsVienPhi[i].code, dsVienPhi[i].name, dsVienPhi[i].fee);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Khong tim thay ma vien phi nay!\n");
            }
            break;
        case 2:
            printf("Nhap ten vien phi muon tim kiem: ");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            for (int i = 0; i < numVienPhi; ++i) {
                if (strcmp(dsVienPhi[i].name, name) == 0) {
                    printf("Ma: %s, Ten: %s, Gia: %lu\n", dsVienPhi[i].code, dsVienPhi[i].name, dsVienPhi[i].fee);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Khong tim thay ten vien phi nay!\n");
            }
            break;
    }
}

void calculateInvoice(const struct VienPhi dsVienPhi[], int numVienPhi) {       //Hàm tính toán và in ra hóa đơn
    char ten[50], address[100], date[20];
    printf("Nhap ten benh nhan: ");
    getchar();
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    printf("Nhap ngay thang nam sinh: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    printf("Nhap dia chi: ");
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = '\0';
    int numOfMedicine, numOfService, numOfUseDay;
    unsigned long tongTien = 0;
    char code[4];
    while (1) {
        printf("So luong ma thuoc: ");
        if (scanf("%d", &numOfMedicine) != 1 || numOfMedicine < 0) {
            printf("Loi: Ban phai nhap mot so nguyen khong am. Vui long thu lai.\n");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    }
    struct VienPhi *medicine = (struct VienPhi *)malloc(numOfMedicine * sizeof(struct VienPhi));
    int *numOfEachMedicine = (int *)malloc(numOfMedicine * sizeof(int));
    if (numOfMedicine != 0) {
        for (int i = 0; i < numOfMedicine; i++) {
            printf("Nhap ma thuoc: ");
            scanf("%3s", code);
            for (int j = 0; j < numVienPhi; j++) {
                if (strcmp(dsVienPhi[j].code, code) == 0) {
                    medicine[i] = dsVienPhi[j];
                    while (1) {
                        printf("So luong %s:", dsVienPhi[j].name);
                        if (scanf("%d", &numOfEachMedicine[i]) != 1 || numOfEachMedicine[i] <= 0) {
                            printf("Loi: Ban phai nhap mot so nguyen duong. Vui long thu lai.\n");
                            while (getchar() != '\n');
                        }
                        else {
                            break;
                        }
                    }
                    tongTien += numOfEachMedicine[i] * dsVienPhi[j].fee;
                }
            }
        }
    }
    while (1) {
        printf("So luong ma dich vu: ");
        if (scanf("%d", &numOfService) != 1 || numOfService < 0) {
            printf("Loi: Ban phai nhap mot so nguyen khong am. Vui long thu lai.\n");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    }
    struct VienPhi *service = (struct VienPhi *)malloc(numOfService * sizeof(struct VienPhi));
    if (numOfService != 0) {
        for (int i = 0; i < numOfService; i++) {
            printf("Nhap ma dich vu: ");
            scanf("%3s", code);
            for (int j = 0; j < numVienPhi; j++) {
                if (strcmp(dsVienPhi[j].code, code) == 0) {
                    service[i] = dsVienPhi[j];
                    tongTien += dsVienPhi[j].fee;
                    break;
                }
            }
        }
    }
    printf("Nhap ma phong da su dung: ");
    scanf("%3s", code);
    struct VienPhi phong;
    for (int j = 0; j < numVienPhi; j++) {
        if (strcmp(dsVienPhi[j].code, code) == 0) {
            phong = dsVienPhi[j];
            while (1) {
                printf("So ngay su dung %s:", dsVienPhi[j].name);
                if (scanf("%d", &numOfUseDay) != 1 || numOfUseDay < 0) {
                    printf("Loi: Ban phai nhap mot so nguyen khong am. Vui long thu lai.\n");
                    while (getchar() != '\n');
                }
                else {
                    break;
                }
            }
            tongTien += numOfUseDay * dsVienPhi[j].fee;
            break;
        }
    }
    system("cls");
    printf("**\t\tHOA DON VIEN PHI\t\t**\n");
    printf("Ten benh nhan: %s\n", ten);
    printf("Ngay thang nam sinh: %s\n", date);
    printf("Dia chi: %s\n", address);
    printf("Ma vien phi\t\tTen vien phi\t\tGia vien phi\t\tSo luong\t\tThanh tien\n");
    for (int i = 0; i < numOfMedicine; i++) {
        int len = strlen(medicine[i].name);
        if (len < 8) {
            printf("%s\t\t\t%s\t\t\t%lu\t\t\t%d\t\t\t%lu\n", medicine[i].code, medicine[i].name, medicine[i].fee, numOfEachMedicine[i], numOfEachMedicine[i]*medicine[i].fee);
        }
        else if ((len >=8) && (len < 16)) {
            printf("%s\t\t\t%s\t\t%lu\t\t\t%d\t\t\t%lu\n", medicine[i].code, medicine[i].name, medicine[i].fee, numOfEachMedicine[i], numOfEachMedicine[i]*medicine[i].fee);
        }
        else {
            printf("%s\t\t\t%s\t%lu\t\t\t%d\t\t\t%lu\n", medicine[i].code, medicine[i].name, medicine[i].fee, numOfEachMedicine[i], numOfEachMedicine[i]*medicine[i].fee);
        }
    }
    for (int i = 0; i < numOfService; i++) {
        int len = strlen(service[i].name);
        if(len < 8) {
            printf("%s\t\t\t%s\t\t\t%lu\t\t\t%d\t\t\t%lu\n", service[i].code, service[i].name, service[i].fee, 1, service[i].fee);
        }
        else if ((len >=8) && (len < 16)) {
            printf("%s\t\t\t%s\t\t%lu\t\t\t%d\t\t\t%lu\n", service[i].code, service[i].name, service[i].fee, 1, service[i].fee);
        }
        else {
            printf("%s\t\t\t%s\t%lu\t\t\t%d\t\t\t%lu\n", service[i].code, service[i].name, service[i].fee, 1, service[i].fee);
        }
    }
    printf("%s\t\t\t%s\t\t\t%lu\t\t\t%d\t\t\t%lu\n", phong.code, phong.name, phong.fee, numOfUseDay, numOfUseDay* phong.fee);
    printf("So tien can thanh toan: %lu\n", tongTien);
    free(medicine);
    free(numOfEachMedicine);
    free(service);
}

int exitVP(const struct VienPhi dsVienPhi[], int numVienPhi) {          //Hàm thoát ghi dữ liệu vào file "vienphi.data" và thoát chương trình
    char choice;
    printf("Ban co chac chan muon thoat chuong trinh ?\nCo/khong ? ");
    scanf(" %c", &choice);
    if (choice == 'C' || choice == 'c') {
        writeToFile(dsVienPhi, numVienPhi);
        printf("Ban da thoat chuong trinh!");
        exit(0);
    }
}

int main() {
    char choice;
    struct VienPhi dsVienPhi[MAX_VIEN_PHI];
    int numVienPhi = 0;
    readFromFile(dsVienPhi, &numVienPhi);
    while (1) {
        menu();
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("**\t\tTao vien phi\t\t**\n");
                add(dsVienPhi, &numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            case '2':
                printf("**\t\tHien thi vien phi\t\t**\n");
                display(dsVienPhi, numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            case '3':
                printf("**\t\tSua vien phi\t\t**\n");
                modify(dsVienPhi, numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            case '4':
                printf("**\t\tXoa vien phi\t\t**\n");
                deleteVP(dsVienPhi, &numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            case '5':
                printf("**\t\tSap xep vien phi\t\t**\n");
                arrange(dsVienPhi, numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            case '6':
                printf("**\t\tTim kiem vien phi\t\t**\n");
                findVP(dsVienPhi, numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            case '7':
                printf("**\t\tIn hoa don vien phi\t\t**\n");
                calculateInvoice(dsVienPhi, numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            case '0':
                exitVP(dsVienPhi, numVienPhi);
                printf("Enter any key to continue...");
                getch();
                break;
            default:
                printf("Lua chon khong hop le!\n");
                printf("Enter any key to continue...");
                getch();
                break;
        }
    }
    return 0;
}
