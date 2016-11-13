#include<stdio.h>
#include<stdlib.h>

int n;
int main()
{
	int gcd(int y[]);
	FILE  *fp; 
    int k;
	int ee=0;
	int i, j, h;
	int a[2002]={0};                                       //后面多项式平方后，次数可能会大于1000，因此取极大值2002，防止溢出
	a[0]=1;
	fp = fopen("输出1.txt", "w+");
	for(n=3;n<=1000;n++){
		k=0;
		a[n]=1;                                                   //检验重量为3的所有n次多项式   是否存在不可约的
		for(j=1;j<n;j++){
			a[j]=1;
		    if(gcd(a)==1){                                   //1表示不可约
				if(k==0){
					printf("%4d次     3  ",n);
					fprintf(fp,"%4d次     3  ",n);
				}
				else{
					printf("                   ");
					fprintf(fp,"                    ");
				}
				printf("x^%d+ ",n);                                                 //重量已知，即要输出的位置已知，直接输出比循环输出要更快
				fprintf(fp,"x^%d+ ",n);
				printf("x^%d+ ",j);
				fprintf(fp,"x^%d+ ",j);
				printf("1\n");
				fprintf(fp,"1\n");
				k=1;                            //k为判断值，记录是否有不可约
			}
			a[j]=0;
			if(k==1)
			break;
		}
		if(n>=5&&k==0){                                //重数不为3时，考虑为5的情况
            ee=0;		
			for(i=1;i<=n-3;i++){
				a[i]=1;
				for(j=i+1;j<=n-2;j++){
					a[j]=1;
					for(h=j+1;h<=n-1;h++){
						a[h]=1;
						if(gcd(a)==1)                                   //1表示不可约
					                   {
						                 printf("%4d次  5     ",n);                                  //直接输出比循环判断再输出要快
						                 fprintf(fp,"%4d次  5     ",n);
					                     printf("x^%d+ ",n);
								         fprintf(fp,"x^%d+ ",n);
										 printf("x^%d+ ",h);
								         fprintf(fp,"x^%d+ ",h);
										 printf("x^%d+ ",j);
								         fprintf(fp,"x^%d+ ",j);
										 printf("x^%d+ ",i);
								         fprintf(fp,"x^%d+ ",i);
						                  printf("1\n");
						                  fprintf(fp,"1\n");
										  ee=1;
							          }
							       a[h]=0;
								   if(ee==1)
									   break;
							     }
					a[j]=0;
					if(ee==1)
						break;
					}
			a[i]=0;
			if(ee==1)
				break;
			}
		}
	a[n]=0;
		
}
fclose(fp);
	
	return 0;
}
int gcd(int y[])                        //x表示次数n
{ 
		int judge(int m[],int v[],int z);

		int num=2002;
		int p=0,q;
		int i,j, k,s;
		int b[2002]={0};                   //存储x的2的i次幂   这个多项式
		int c[2002]={0};
		
		b[1]=1;
		for(i=1;i<=(n/2)+1;i++)
		{
			for(s=n;s>=0;s--)
				c[s]=0;
			for(j=n;j>=0;j--)
				{if(b[j]==1)
					{
						for(k=n;k>=0;k--)
						    { if(b[k]==1)
							c[j+k]+=1;
						     c[j+k]=c[j+k]%2;}        
			        }     
			}
			for(s=2002;s>=0;s--)                  //找出c的次数，记为q
				{if(c[s]==1)
					{
						q=s;
						break;
			        }
			    }
			while(q>=n&&q<2002)                                          //模f运算
				{
					num=2002;
					for(s=n;s>=0;s--)
					    {
						  b[s]=0;                             //b在此处暂时作为中转量，b表示f乘上x的次幂后
						  b[s+(q-n)]=y[s];
				         }
			       for(s=0;s<=q;s++)
			            {
						  c[s]=c[s]+b[s];                    //相减运算
						  c[s]=c[s]%2;
						  if(c[s]==1)
							  num=s;
				        }
				   q=num;
			    }

			for(s=n;s>=0;s--)
				b[s]=c[s];                                       //为下次用b做准备
			c[1]+=1;                                         //加上一个x，c已经确定
		    c[1]=c[1]%2;
			
           if(q==2002)
			   {
				   q=1;
			   }
		   if(q==0)
			   q=1;
		   if(q==1)
			   if(c[0]==1)
				   {
					   p=0;
					   break;
			        }
			   else
				   {
					   p=1;
					   break;
			       }

            if(judge(c,y,q)==0)                 //0表示不互素     1表示互素
				  {
					p=1;
				    break;                              //出现不互素情况则可以跳出
			       }             
		 



		}
		if(p==0)                           //p=0表示没有不互素，即符合不可约
			return 1;
		else
			return 0;
	}

int judge(int m[],int v[],int z ){                         //m即为c，f为最初的f
	int i;
	int s,r;                     //备用变量
	int k=1002,p=2;
	int f[2002]={0}, t[2002]={0};    //待会儿用m表示次数较大的，f表示次数较小的，t作为中转待命
	int mm,ff;             //mm，ff分别记录m和f的次数 
	for(s=0;s<=n;s++)
		f[s]=v[s];
	mm=z;
	ff=n;
	while(1){
		if(mm<ff){                        //调整形式
			for(i=0;i<=n;i++){
				t[i]=m[i];
				m[i]=f[i];
				f[i]=t[i];
			}
		    s=mm;
			mm=ff;
			ff=s;
		}
		s=mm-ff;
		if(s!=0)
			for(i=ff;i>=0;i--){              //次数低的乘上一个x的次幂
				f[i+s]=f[i];
		     	f[i]=0;
		    }
		for(i=0;i<=mm;i++){         //从低次开始便于记录余式的次数
			t[i]=m[i]+f[i];
			t[i]=t[i]%2;
			if(t[i]==1)
				k=i;
		}
		if(k==0)                         //表示余式为1,互素
			{p=1;
		     break;
		    }
		if(k==1002)                      //表示余式为0，即出现整除，不可约
           {p=0;
		    break; 
		   }
		
		if(s!=0)
		{
			for(r=s;r<=mm;r++)
			{
				f[r-s]=f[r];
				f[r]=0;
		    }
		}
			         
		for(i=0;i<=mm;i++)                   //暂时将余式赋给m，判断留给下个循环开始时
			    {
				    m[i]=t[i];
        		}
		mm=k;

		k=1002;                  //应对余式为0的情况
	   }
       return p;
}
