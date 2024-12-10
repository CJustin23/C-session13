#include<stdio.h>
void Menu(){
	printf("----------MENU----------\n\n");
	printf("1.Nhap gia tri cac phan tu cua mang\n");
	printf("2.In ra cac phan tu cua mang theo ma tran\n");
	printf("3.In ra cac phan tu o goc theo ma tran\n");
	printf("4.In ra cac phan tu nam tren duong bien ma tran\n");
	printf("5.In ra cac phan tu nam tren duong cheo chinh va duong cheo phu\n");
	printf("6.In ra cac phan tu la so nguyen to theo ma tran\n");
	printf("7.Thoat\n\n");
}
// Lua chon 1
void AddItem(int arr[][100],int m,int n){
	for (int i = 0;i < m;i++){
		for (int j = 0;j < n;j++){
			printf("Hay nhap phan tu hang %d cot %d: ",i + 1,j + 1);
			scanf("%d",&arr[i][j]);
		}
	}
}
//Lua chon 2
void PrintMatrix(int arr[][100],int m,int n){
    if (m == 0 && n == 0){
    	printf("Mang trong\n");
	}
	else{
		printf("Ma tran:\n");
	    for (int i = 0;i < m;i++){
		    for (int j = 0;j < n;j++){
			    printf("%d  ",arr[i][j]);
		    }
		    printf("\n");
	    }
	}
}
//Lua chon 3
void PrintCorners(int arr[][100],int m,int n){
	if (m == 0 && n == 0){
    	printf("Mang trong\n");
	}
	else{
		printf("Cac phan tu o goc:\n");
	    for (int i = 0;i < m;i++){
		    for (int j = 0;j < n;j++){
		    	if ((i == m - 1 && j == n - 1 )|| (i == 0 && j == n - 1) || (i == m - 1 && j == 0) || (i == 0 && j == 0)){
		    		printf("%d  ",arr[i][j]);
				}
				else{
					printf("0  ");
				}
		    }
		    printf("\n");
	    }
	}
}
// lua chon 4
void PrintBorders(int arr[][100],int m,int n){
    if (m == 0 && n == 0){
    	printf("Mang trong\n");
	}
	else{
		printf("Duong bien:\n");
	    for (int i = 0;i < m;i++){
		    for (int j = 0;j < n;j++){
			    if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
			    	printf("%d  ",arr[i][j]);
				}
				else{
					printf("0  ");
				}
		    }
		    printf("\n");
	    }
	}
}
// Lua chon 5
void PrintDiagonals(int arr[][100],int m,int n){
	if (m == 0 && n == 0){
    	printf("Mang trong\n");
	}
	else{
		printf("Duong cheo chinh va phu:\n");
	    for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) {
                    printf("%d  ", arr[i][j]);
                }
				else {
                    printf("0  ");
                }
            }
            printf("\n");
        }	
	}
}
// Lua chon 6
void PrintPrimes(int arr[][100],int m,int n){
	if (m == 0 && n == 0){
    	printf("Mang trong\n");
	}
	else{
		printf("So nguyen to:\n");
		for (int i = 0;i < m;i++){
			for (int j = 0;j < n;j++){
				int count = 0;
				for (int k = 1;k < arr[i][j];k++){
					if (arr[i][j] % k == 0){
						count++;
					}
				}
				if (count == 1){
					printf("%d  ",arr[i][j]);
				}
				else{
					printf("0  ");
				}
			}
			printf("\n");
		}
	}
}

int main(){
	int a = 0;
	int b = 0;
	int arr[100][100];
    int choice;
    while (choice != 7){
    	Menu();
    	printf("Lua chon cua ban: ");
    	scanf("%d",&choice);
    	switch (choice){
    		case 1:{
    			printf("Hay nhap so hang cua ma tran: ");
    			scanf("%d",&a);
    			printf("Hay nhap so cot cua ma tran: ");
    			scanf("%d",&b);
    			if (a <= 1 || b <= 1){
    				printf("Kich thuoc mang khong hop le\n");
    				a = 0;
    				b = 0;
				}
				else{
					AddItem(arr,a,b);
				}
				break;
			}
			case 2:{
				PrintMatrix(arr,a,b);
				break;
			}
			case 3:{
				PrintCorners(arr,a,b);
				break;
			}
			case 4:{
				PrintBorders(arr,a,b);
				break;
			}
			case 5:{
				PrintDiagonals(arr,a,b);
				break;
			}
			case 6:{
				PrintPrimes(arr,a,b);
				break;
			}
			case 7:{
				printf("Thoat chuong trinh\n");
				break;
			}
			default:{
				printf("Lua chon khong hop le\n");
			}
		}
	}
	
	return 0;
}

