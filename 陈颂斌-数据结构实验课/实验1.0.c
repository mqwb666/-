#include "stdio.h"

int fun1(int a,int b,int c)
{
	int flag=0;
	if(a==0)
	{
		printf("���Ƕ�Ԫһ�η���");
		flag=1;
	}
	return flag;
}

void fun2(int a,int b,int c)
{
	if(b*b-4*a*c<0)
	{
		printf("�޽�");
	}
}
void fun3(int a,int b,int c)
{
	if(b*b-4*a*c>=0)
	{
		printf("�н�");
	}
}
int main()
{
	int a,b,c;
	printf("�����������\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("�����ǣ�%dx^2+%dx+%d=0\n",a,b,c);
	if(fun1(a,b,c)==0)
	{
		fun2(a,b,c);
		fun3(a,b,c);
	}
	return 0;
}
