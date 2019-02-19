#include <stdio.h>
#include <string.h>
#define DEL() while(getchar() != '\n')

typedef char name[31];
typedef struct _tenViet {
    char ho[30];
    char dem[30];
    char ten[30];
} tenViet;

int num_sv = 0;
int n = 0;

void menu1();
void menu2();
void menu3();
void menu4();
void listAdd(name);
void listPrint();
void sapXepTenViet();
tenViet tachTen(name);
int soSanhTenViet(name, name);

name nameList[100];
int lengthNameList = 0;

int main() {
    int choose;
    do {
        printf("       MENU\n");
        printf("1.Nhap ten sinh vien\n");
        printf("2.Sap xep ten\n");
        printf("3.In danh sach\n");
        printf("4.Ket thuc\n");
        printf("\tBan chon:");
        scanf("%d",&choose); DEL();
        switch (choose)
        {
            case 1:
                menu1(); break;
            case 2:
                menu2(); break;
            case 3:
                menu3(); break;
            case 4:
                menu4(); break;
            default:
                printf("Ban chon sai!Chon lai\n");
        }
    } while (choose != 4);
}

void menu1() {
    int n = 0, i = 0;
    name ten;

    printf ("So luong ten ban muon nhap: ");
    scanf("%d", &n); DEL();

    for (i = 0; i < n; i++) {
        printf("Ten thu %d: ", i + 1);
        scanf("%[^\n]", ten); DEL();
        listAdd(ten);
    }
}

void menu2() {
    sapXepTenViet();
    printf("Sap xep xong\n");
}

void menu3() {
    listPrint();
}

void menu4() {
    printf("Ket thuc chuong trinh\n");
}

void listAdd(name ten) {
    if (lengthNameList >= 100) {
        printf("Danh sach ten da het cho chua");
        return;
    }
    strcpy(nameList[lengthNameList], ten);
    lengthNameList++;
}

void listPrint() {
    if (lengthNameList == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("Danh sach ten\n");

    int i;

    for (i = 0; i < lengthNameList; i++) {
        printf("%d\t%s\n", i + 1, nameList[i]);
    }
}

void sapXepTenViet() {
    int i, j, min;
    name tmp;

    for (i = 0; i < lengthNameList; i++) {
        min = i;
        for (j = i + 1; j < lengthNameList; j++) {
            if (soSanhTenViet(nameList[j], nameList[min]) < 0) {
                min = j;
            }
        }
        strcpy(tmp, nameList[i]);
        strcpy(nameList[i], nameList[min]);
        strcpy(nameList[min], tmp);
    }
}

tenViet tachTen(name ten) {
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

    if (firstSpace < lastSpace) {
        memcpy(tenviet.dem, &ten[firstSpace + 1], lastSpace - firstSpace - 1);
        tenviet.dem[lastSpace - firstSpace - 1] = '\0';
    }

    return tenviet;
}

int soSanhTenViet(name a, name b) {
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


