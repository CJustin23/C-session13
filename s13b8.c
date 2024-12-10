#include<stdio.h>
void UCLN(int a, int b){
	int temp;
	while(b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	printf("Uoc chung lon nhat cua 2 so la: %d",a);
} 
int main(){
    int m = 20;
    int n = 12;
    UCLN(m, n);
    
	return 0;
}

