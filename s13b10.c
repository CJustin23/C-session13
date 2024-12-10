#include <stdio.h>

int arr[100];
int n = 0;

void nhapMang() {
    printf("Nhap so phan tu can nhap: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inMang() {
    printf("Cac phan tu trong mang:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu(int viTri, int giaTri) {
    if (n >= 100 || viTri < 0 || viTri > n) {
        printf("Khong the them phan tu.\n");
        return;
    }
    for(int i = n; i > viTri; i--) {
        arr[i] = arr[i-1];
    }
    arr[viTri] = giaTri;
    n++;
}

void suaPhanTu(int viTri, int giaTri) {
    if (viTri >= 0 && viTri < n) {
        arr[viTri] = giaTri;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

void xoaPhanTu(int viTri) {
    if (viTri >= 0 && viTri < n) {
        for(int i = viTri; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

void sapXepMang(char order) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if ((order == 'a' && arr[i] < arr[j]) || (order == 'b' && arr[i] > arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void hienThiMenu() {
    printf("MENU\n1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n   a. Giam dan\n   b. Tang dan\n");
    printf("7. Thoat\n");
}

int main() {
    int choice, viTri, giaTri;
    char subchoice;

    do {
        hienThiMenu();
        printf("Chon mot chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                printf("Nhap vi tri can them: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri can them: ");
                scanf("%d", &giaTri);
                themPhanTu(viTri, giaTri);
                break;
            case 4:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri moi: ");
                scanf("%d", &giaTri);
                suaPhanTu(viTri, giaTri);
                break;
            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                xoaPhanTu(viTri);
                break;
            case 6:
                printf("Chon cach sap xep:\n   a. Giam dan\n   b. Tang dan\n");
                getchar(); 
                subchoice = getchar();
                if (subchoice == 'a' || subchoice == 'b') {
                    sapXepMang(subchoice);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);

    return 0;
}
