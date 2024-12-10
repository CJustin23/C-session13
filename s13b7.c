#include<stdio.h>
void Matrix(int hang, int cot){
	int arr[hang][cot];
	for (int i = 0;i < hang;i++){
		for (int j = 0;j < cot;j++){
			printf("Hay nhap arr[%d][%d]: ", i + 1, j + 1);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Ma tran:\n");
	for (int i = 0;i < hang;i++){
	    for (int j = 0;j < cot;j++){
	    	printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
}
int main(){
    int a, b;
    printf("Hay nhap so hang cua ma tran: ");
    scanf("%d",&a);
    printf("Hay nhap so cot cua ma tran: ");
    scanf("%d",&b);
    if (a > 1 && b > 1){
    	Matrix(a, b);
	}
	else{
		printf("Kich thuoc ma tran khong hop le\n");
	}
    
	return 0;
}

