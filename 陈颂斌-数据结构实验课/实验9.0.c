#include<stdio.h>

void output(int a[],int m,int n){
	int i;
	for(i=0;a[i]!=m&&i<n;i++){
		printf("第%d次与%d比较\n",i+1,a[i]);
	}
	if(i<n){
		printf("第%d次与%d比较\n",i+1,a[i]);
		printf("%d是表中第%d个元素\n",a[i],i+1);
	}else{
		printf("未找到\n"); 
	}
}

void input(int a[],int m,int n){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
} 

int BiSearch(int a[],int key,int n){
	int i=1;
	int low=0,high=n-1,mid;
	while(low<=high){
		mid = (low+high)/2;
		printf("第%d次与%d比较\n",i++,a[mid]);
		if(key == a[mid]){
			printf("%d是表中第%d个元素\n",a[mid],mid+1);
			return ;
		}
		else if(key > a[mid]){
			low = mid + 1;
		}else if(key < a[mid]){
			high = mid - 1;
		}		
	}
	printf("未找到");
	return ; 
}

void main(){
	int a[20],n,m;
	printf("顺序查找\n");
	printf("请输入元素个数且个数小于20：");
	scanf("%d",&n);
	printf("依次输入元素：");
	input(a,m,n);
	printf("输入要查找的元素：");
	scanf("%d",&m);
	output(a,m,n);
	
	printf("\n======================\n\n");
	
	printf("折半查找\n");
	printf("请输入元素个数且个数小于20：");
	scanf("%d",&n);
	printf("依次输入增序元素：");
	input(a,m,n);
	printf("输入要查找的元素：");
	scanf("%d",&m);
	BiSearch(a,m,n);
	
	
} 
