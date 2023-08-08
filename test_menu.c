#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct phong_tro {
    char ten[4];
    int dien_tich;
    int dieu_hoa;
};

struct phong_tro *arr_phong_tro = NULL; // Declare a global pointer

void allocateArray(int size) {
    arr_phong_tro = (struct phong_tro *)malloc(size * sizeof(struct phong_tro));
    if (arr_phong_tro == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

int menu(){
    system("cls");
    printf("Cac chuc nang: \n");
    printf("1. Nhap thong tin phong tro: \n");
    printf("2. In thong tin cac nha hang: \n");
    printf("3. Tim kiem theo dien tich: \n");
    printf("4. Sap xep: \n");
    printf("5. Thong ke so luong dieu hoa can bo sung: \n");
    printf("6. Thoat. \n");
    printf("Moi ban chon chuc nang: ");
    int cn;
    scanf("%d", &cn);
    return cn;
}

int so_phong = 0;
int phong_them = 0;

void chuc_nang_1(){
    system("cls");
    nhap:
    printf("Nhap vao so phong tro: \n");
    scanf("%d", &phong_them);
    int so_phong_moi = so_phong + phong_them;
    arr_phong_tro = (struct phong_tro *)realloc(arr_phong_tro, so_phong_moi * sizeof(struct phong_tro));
    if (arr_phong_tro == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    if(phong_them < 0){
        printf("So phong nhap vao khong hop le. Vui long nhap lai so phong.");
        goto nhap;
    }else{
        for(int i = so_phong; i <so_phong_moi; i++){
            char ten_cua_phong[100];
            int area = 0;
            int eacon = 0;
            printf("Nhap thong tin cho phong tro thu %d\n", i+1);

            //Nhap ten phong tro thu i
            nhapten:
            printf("Nhap ten cho phong tro: \n");
            scanf("%s", ten_cua_phong);
                if(strlen(ten_cua_phong) > 4){
                    printf("Ten nhap vao khong hop le");
                    goto nhapten;
                }
            strcpy(arr_phong_tro[i].ten,ten_cua_phong);

            //Nhap dien tich phong tro
            while (1) {
                printf("Nhap dien tich cho phong tro: \n");
                scanf("%d", &area);

                if (area < 10 || area > 40) {
                printf("Vui long nhap lai dien tich phong\n");
                } else {
                arr_phong_tro[i].dien_tich = area;
                break;
                }
            }

            //Nhap dieu hoa phong tro
            nhapeacon:
            printf("Nhap dieu hoa cho phong tro: , voi 0 la chua lap 1 la da lap.\n");
            scanf("%d", &eacon);
            if (eacon != 1 && eacon != 0){
                printf("Vui long nhap lai dieu hoa");
                goto nhapeacon;
            }
                arr_phong_tro[i].dieu_hoa = eacon;
        }
        printf("\n");
        so_phong = so_phong_moi;
    }
}

void chuc_nang_2(int n){
    system("cls");
    printf("%-20s %-20s %-20s\n","Ten Phong", "Dien tich","Dieu hoa");
    for (int i = 0; i < n; i++){
    printf("%-20s %-20d %-20d\n",arr_phong_tro[i].ten, arr_phong_tro[i].dien_tich, arr_phong_tro[i].dieu_hoa);
    }
    getch();
}

void chuc_nang_3(int n){
    system("cls");
    int dien_tich_can_tim;
    int dem = 0;
    printf("Nhap vao dien tich can tim: \n");
    scanf("%d", &dien_tich_can_tim);
    for(int i = 0; i < n; i++){
        if(arr_phong_tro[i].dien_tich <= (dien_tich_can_tim + 5) && arr_phong_tro[i].dien_tich >= (dien_tich_can_tim - 5)){
            printf("Phong tro hop le: %s\n",arr_phong_tro[i].ten);
            dem++;
        }
    }
    if(dem == 0){
        printf("Khong tim thay phong tro hop le.");
    }
    getch();
}

void chuc_nang_4(int n){
    system("cls");
    printf("%-20s %-20s %-20s\n","Ten Phong", "Dien tich","Dieu hoa");
    for (int i = 0; i < n - 1 ; i++){
        for (int j = 0; j < n - i -1; j++){
            struct phong_tro temp = arr_phong_tro[j];
            arr_phong_tro[j] = arr_phong_tro[j+1];
            arr_phong_tro[j+1] = temp;
        }
    for (int i = 0; i < n; i++){
        printf("%-20s %-20d %-20d\n",arr_phong_tro[i].ten, arr_phong_tro[i].dien_tich, arr_phong_tro[i].dieu_hoa);
    }
    getch();
}
}

void chuc_nang_5(int n){
    system("cls");
    int dem1 = 0,dem2 = 0,dem3 = 0,dem4 = 0;
    for (int i = 0; i < n; i++){
            if(arr_phong_tro[i].dieu_hoa == 0){
                if(arr_phong_tro[i].dien_tich < 15){
                    dem1++;
                }
                if(arr_phong_tro[i].dien_tich >= 15 && arr_phong_tro[i].dien_tich < 22){
                    dem2++;
                }
                if(arr_phong_tro[i].dien_tich >= 22 && arr_phong_tro[i].dien_tich < 30){
                    dem3++;
                }
                if(arr_phong_tro[i].dien_tich >= 30 && arr_phong_tro[i].dien_tich < 44){
                    dem4++;
                }
            }
    }
    printf("9000BTU:%d\n12000BTU:%d\n18000BTU:%d\n21000BTU:%d\n", dem1,dem2,dem3,dem4);
    getch();
}

int main (){
     while(1){
        int cn = menu();
        if(cn>6 || cn <1)
            continue;
        switch(cn){
            case 1:
                chuc_nang_1();
                break;
            case 2:
                chuc_nang_2(so_phong);
                break;
            case 3:
                chuc_nang_3(so_phong);
                break;
            case 4:
                chuc_nang_4(so_phong);
                break;
            case 5:
                chuc_nang_5(so_phong);
                break;
            case 6:
                exit(0);
                break;
        }

    }
    free(arr_phong_tro);
    return 0;
}
