#include <stdio.h>
#include <stdlib.h>

int n;
void Create(int a[]){
	int i;
	printf("���������");
	scanf("%d",&n);
	printf("������%d����Ԫ�أ�",n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);	
	}
}

void OutPut(int a[]){
	int i;
	for(i=1;i<=n;i++){
		printf("    %d",a[i]);	
	}	

}

void InsertSort(int a[]){
	int i,j;
	for(i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			a[0]=a[i];
			for(j=i-1;a[0]<a[j];j--){
				a[j+1]=a[j];
			}
			a[j+1]=a[0];
		}
	printf("��%d������",i-1);
	OutPut(a);
	printf("\n");
	}                              
} 

int i = 1;
int Partition(int a[],int low ,int high){
	a[0]=a[low];
	while(high>low){
		while(high>low&&a[high]>=a[0]) high--;
		a[low]=a[high];
		while(high>low&&a[low]<=a[0]) low++;
		a[high]=a[low];
	}
	a[low]=a[0];
	printf("��%d������",i++);
	OutPut(a);
	printf("\n");
	return low;
}

void QSort(int a[],int low ,int high){
	int pivotloc;
	if(low<high){
		pivotloc=Partition(a,low,high);
		QSort(a,low,pivotloc-1);
		QSort(a,pivotloc+1,high);
	}
}

int main(){
	int a[20]; 
	printf("ֱ�Ӳ�������\n\n");
	Create(a);
	InsertSort(a);
	
	printf("\n\n=======================\n\n");
	
	printf("��������\n\n");
	Create(a);
	QSort(a,1,n);
}

