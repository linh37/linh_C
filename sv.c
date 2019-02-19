#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEL() while(getchar() != '\n')

typedef struct _sinhvien {
    char shsv[9];
    char *hoTen;
    char *lop;
    char gioiTinh;
    float diemCSB;
} Ntype;

#include "linkedlist.h"

linked_list ds;

typedef struct _tenViet {
    char ho[30];
    char dem[30];
    char ten[30];
} tenViet;

tenViet tachTen(char *name);

int soSanhTenViet(char *a, char *b);

int soSanhSinhVien(Ntype a, Ntype b);

void bosungdiem(char *lop, char *ten);

void themSinhVien(linked_list ds, char shsv[9], char *hoTen, char *lop, char gioiTinh, float diemCSB);

void printNode(int idx, Ntype a);

void inDanhSach(linked_list ds);

int main() {
    ds = createLinkedList();
    int n, i;
    char hoTen[30], shsv[9], lop[20], gioiTinh;
    float diemCSB;
    int choose;
    do {
        printf("===================================\n");
        printf("                MENU\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. In danh sach sinh vien \n");
        printf("3. Bo sung diem\n");
        printf("4. Thoat\n");
        printf("\tBan chon: ");
        scanf("%d", &choose);
        DEL();

        switch (choose) {
            case 1:
                printf("Ban muon them bao nhieu sinh vien: ");
                scanf("%d", &n);
                DEL();

                for (i = 0; i < n; i++) {
                    printf("Nhap sinh vien thu %d\n", (i + 1));
                    printf("\tHo ten: ");
                    scanf("%[^\n]", hoTen);
                    DEL();
                    printf("\tSHSV: ");
                    scanf("%s", shsv);
                    DEL();
                    printf("\tLop: ");
                    scanf("%[^\n]", lop);
                    DEL();
                    do {
                        printf("Gioi tinh (M/F): ");
                        scanf("%c", &gioiTinh);
                        DEL();
                    } while (gioiTinh != 'M' && gioiTinh != 'F');
                    printf("Diem CSB: ");
                    scanf("%f", &diemCSB);
                    DEL();
                    themSinhVien(ds, shsv, hoTen, lop, gioiTinh, diemCSB);
                }

                break;
            case 2:
                inDanhSach(ds);
                break;
            case 3:
                printf("Nhap lop: \n");
                scanf("%[^\n]", lop); DEL();
                printf("Nhap ten sinh vien: \n");
                scanf("%[^\n]", hoTen); DEL();
                bosungdiem(lop, hoTen);
                break;
            case 4:
                printf("Ket thuc chuong trinh\n");
                break;
            default:
                printf("Ban chon sai. Chon lai!\n\n");
        }
    } while (choose != 4);
}

void themSinhVien(linked_list ds, char shsv[], char hoTen[], char lop[], char gioiTinh, float diemCSB) {
    Ntype a;

    strcpy(a.shsv, shsv);
    a.hoTen = (char *) malloc((strlen(hoTen) + 1) * sizeof(char));
    strcpy(a.hoTen, hoTen);
    a.lop = (char *) malloc((strlen(lop) + 1) * sizeof(char));
    strcpy(a.lop, lop);

    a.gioiTinh = gioiTinh;
    a.diemCSB = diemCSB;

    push(ds, a);
    sort(ds, soSanhSinhVien, "DESC"); // so sanh tu thap den cao
}

void inDanhSach(linked_list ds) {
    printf("%-10s\t %-30s\t %-9s\t %-9s\t %-8s\n", "Lop", "Ten", "SHSV", "Gioi tinh", "Diem CSB");
    print(ds, printNode);
}

void printNode(int idx, Ntype a) {
    printf("%-10s\t %-30s\t %-9s\t %-9c\t %-5.2f\n", a.lop, a.hoTen, a.shsv, a.gioiTinh,
           a.diemCSB);
}

tenViet tachTen(char ten[]) {
    int firstSpace = -1, lastSpace = -1;
    int length = strlen(ten);
    int i = 0;

    for (i = 0; i < length; i++) {
        if (ten[i] == ' ') {
            firstSpace = i;
            break;
        }
    }

    for (i = length - 1; i >= 0; i--) {
        if (ten[i] == ' ') {
            lastSpace = i;
            break;
        }
    }

    tenViet tenviet;

    if (firstSpace < 0) {
        printf("Ten sai dinh dang: %s", ten);
        return tenviet;
    }

    memcpy(tenviet.ho, &ten[0], firstSpace);
    tenviet.ho[firstSpace] = '\0';

    memcpy(tenviet.ten, &ten[lastSpace + 1], length - lastSpace);
    tenviet.ten[length - lastSpace] = '\0';
    return tenviet;
}

int soSanhTenViet(char a[], char b[]) {
    tenViet av = tachTen(a), bv = tachTen(b);

    if (strcmp(av.ten, bv.ten) != 0) {
        return strcmp(av.ten, bv.ten);
    }

    if (strcmp(av.dem, bv.dem) != 0) {
        return strcmp(av.dem, bv.dem);
    }

    if (strcmp(av.ho, bv.ho) != 0) {
        return strcmp(av.ho, bv.ho);
    }

    return 0;
}

int soSanhSinhVien(Ntype a, Ntype b) {
    if (strcmp(a.lop, b.lop) != 0) return strcmp(a.lop, b.lop);
    return soSanhTenViet(a.hoTen, b.hoTen);
}

int soSanhTen(Ntype a, Ntype b) {
    return strcmp(a.hoTen, b.hoTen) || strcmp(a.lop, b.lop);
}

void bosungdiem(char *lop, char *ten) {
    Ntype key;
    key.lop = lop;
    key.hoTen = ten;
    node result = findNode(ds, key, soSanhTen);
    if (result == NULL) {
        printf("Khong co du lieu");
    } else {
        printf("Diem hien tai cua sinh vien: %f\n", result->value->diemCSB);
        float d;
        printf("Bo sung diem: \n");
        scanf("%f", &d);
        DEL();
        result->value->diemCSB = d;
    }
}