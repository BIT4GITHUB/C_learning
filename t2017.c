#include<ctype.h>
#include<stdio.h>

int main()
{
	int n,d;
	char c;
	scanf("%d%*c",&n);    //"%*c"means input a string but don't give any vector!
	while(n--){
		for(d=0;(c=getchar())!='\n';)  
			if(isdigit(c)) d++;   //���ÿ⺯����isdigit()"�ж�һ���ַ��Ƿ�������    
		printf("%d\n",d);
	}
	return 0;
}



