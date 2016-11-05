#include<stdio.h>

int main()
{
	int n,f[100],i,swap,m;
	while(scanf("%d",&n),n){
		m=0;
		for(i=0;i<n;i++){
			scanf("%d",&f[i]);
			if(f[i]<f[m]) m=i;
		}
		swap=f[0];f[0]=f[m];f[m]=swap;
		for(i=0;i<n;i++)
			printf("%d%c",f[i],(i<n-1?' ':'\n'));
	}
	return 0;
}
