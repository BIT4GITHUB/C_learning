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
	int a[2002]={0};                                       //�������ʽƽ���󣬴������ܻ����1000�����ȡ����ֵ2002����ֹ���
	a[0]=1;
	fp = fopen("���1.txt", "w+");
	for(n=3;n<=1000;n++){
		k=0;
		a[n]=1;                                                   //��������Ϊ3������n�ζ���ʽ   �Ƿ���ڲ���Լ��
		for(j=1;j<n;j++){
			a[j]=1;
		    if(gcd(a)==1){                                   //1��ʾ����Լ
				if(k==0){
					printf("%4d��     3  ",n);
					fprintf(fp,"%4d��     3  ",n);
				}
				else{
					printf("                   ");
					fprintf(fp,"                    ");
				}
				printf("x^%d+ ",n);                                                 //������֪����Ҫ�����λ����֪��ֱ�������ѭ�����Ҫ����
				fprintf(fp,"x^%d+ ",n);
				printf("x^%d+ ",j);
				fprintf(fp,"x^%d+ ",j);
				printf("1\n");
				fprintf(fp,"1\n");
				k=1;                            //kΪ�ж�ֵ����¼�Ƿ��в���Լ
			}
			a[j]=0;
			if(k==1)
			break;
		}
		if(n>=5&&k==0){                                //������Ϊ3ʱ������Ϊ5�����
            ee=0;		
			for(i=1;i<=n-3;i++){
				a[i]=1;
				for(j=i+1;j<=n-2;j++){
					a[j]=1;
					for(h=j+1;h<=n-1;h++){
						a[h]=1;
						if(gcd(a)==1)                                   //1��ʾ����Լ
					                   {
						                 printf("%4d��  5     ",n);                                  //ֱ�������ѭ���ж������Ҫ��
						                 fprintf(fp,"%4d��  5     ",n);
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
int gcd(int y[])                        //x��ʾ����n
{ 
		int judge(int m[],int v[],int z);

		int num=2002;
		int p=0,q;
		int i,j, k,s;
		int b[2002]={0};                   //�洢x��2��i����   �������ʽ
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
			for(s=2002;s>=0;s--)                  //�ҳ�c�Ĵ�������Ϊq
				{if(c[s]==1)
					{
						q=s;
						break;
			        }
			    }
			while(q>=n&&q<2002)                                          //ģf����
				{
					num=2002;
					for(s=n;s>=0;s--)
					    {
						  b[s]=0;                             //b�ڴ˴���ʱ��Ϊ��ת����b��ʾf����x�Ĵ��ݺ�
						  b[s+(q-n)]=y[s];
				         }
			       for(s=0;s<=q;s++)
			            {
						  c[s]=c[s]+b[s];                    //�������
						  c[s]=c[s]%2;
						  if(c[s]==1)
							  num=s;
				        }
				   q=num;
			    }

			for(s=n;s>=0;s--)
				b[s]=c[s];                                       //Ϊ�´���b��׼��
			c[1]+=1;                                         //����һ��x��c�Ѿ�ȷ��
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

            if(judge(c,y,q)==0)                 //0��ʾ������     1��ʾ����
				  {
					p=1;
				    break;                              //���ֲ�����������������
			       }             
		 



		}
		if(p==0)                           //p=0��ʾû�в����أ������ϲ���Լ
			return 1;
		else
			return 0;
	}

int judge(int m[],int v[],int z ){                         //m��Ϊc��fΪ�����f
	int i;
	int s,r;                     //���ñ���
	int k=1002,p=2;
	int f[2002]={0}, t[2002]={0};    //�������m��ʾ�����ϴ�ģ�f��ʾ������С�ģ�t��Ϊ��ת����
	int mm,ff;             //mm��ff�ֱ��¼m��f�Ĵ��� 
	for(s=0;s<=n;s++)
		f[s]=v[s];
	mm=z;
	ff=n;
	while(1){
		if(mm<ff){                        //������ʽ
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
			for(i=ff;i>=0;i--){              //�����͵ĳ���һ��x�Ĵ���
				f[i+s]=f[i];
		     	f[i]=0;
		    }
		for(i=0;i<=mm;i++){         //�ӵʹο�ʼ���ڼ�¼��ʽ�Ĵ���
			t[i]=m[i]+f[i];
			t[i]=t[i]%2;
			if(t[i]==1)
				k=i;
		}
		if(k==0)                         //��ʾ��ʽΪ1,����
			{p=1;
		     break;
		    }
		if(k==1002)                      //��ʾ��ʽΪ0������������������Լ
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
			         
		for(i=0;i<=mm;i++)                   //��ʱ����ʽ����m���ж������¸�ѭ����ʼʱ
			    {
				    m[i]=t[i];
        		}
		mm=k;

		k=1002;                  //Ӧ����ʽΪ0�����
	   }
       return p;
}
