#include<ctype.h>
#include<stdio.h>

int main()
{
	int n,d;
	char c;
	scanf("%d%*c",&n);    //"%*c"means input a string but don't give any vector!
	while(n--){
		for(d=0;(c=getchar())!='\n';)  
			if(isdigit(c)) d++;   //调用库函数“isdigit()"判断一个字符是否是数字    
		printf("%d\n",d);
	}
	return 0;
}



