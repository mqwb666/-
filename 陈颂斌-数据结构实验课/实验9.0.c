#include<stdio.h>

void output(int a[],int m,int n){
	int i;
	for(i=0;a[i]!=m&&i<n;i++){
		printf("��%d����%d�Ƚ�\n",i+1,a[i]);
	}
	if(i<n){
		printf("��%d����%d�Ƚ�\n",i+1,a[i]);
		printf("%d�Ǳ��е�%d��Ԫ��\n",a[i],i+1);
	}else{
		printf("δ�ҵ�\n"); 
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
		printf("��%d����%d�Ƚ�\n",i++,a[mid]);
		if(key == a[mid]){
			printf("%d�Ǳ��е�%d��Ԫ��\n",a[mid],mid+1);
			return ;
		}
		else if(key > a[mid]){
			low = mid + 1;
		}else if(key < a[mid]){
			high = mid - 1;
		}		
	}
	printf("δ�ҵ�");
	return ; 
}

void main(){
	int a[20],n,m;
	printf("˳�����\n");
	printf("������Ԫ�ظ����Ҹ���С��20��");
	scanf("%d",&n);
	printf("��������Ԫ�أ�");
	input(a,m,n);
	printf("����Ҫ���ҵ�Ԫ�أ�");
	scanf("%d",&m);
	output(a,m,n);
	
	printf("\n======================\n\n");
	
	printf("�۰����\n");
	printf("������Ԫ�ظ����Ҹ���С��20��");
	scanf("%d",&n);
	printf("������������Ԫ�أ�");
	input(a,m,n);
	printf("����Ҫ���ҵ�Ԫ�أ�");
	scanf("%d",&m);
	BiSearch(a,m,n);
	
	
} 
