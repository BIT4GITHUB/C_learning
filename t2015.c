#include <stdio.h>

int main(void)
{
    int i, n, m, begin, state;
    //�����ǵȲ����е���ͣ��ҳ����еĹ��ɣ���һ���Լ���ȱ�������ǵ�˼ά��ת̬��˼ά�� 
    while (scanf("%d%d", &n, &m) != EOF){
        begin= 2,state= 0;
        for (i = 0 ; i < n / m ; i++) {
            printf(state++ ? " %d" : "%d", begin + m - 1);  //����������������õ�������� 
            begin += m * 2;
        }
        printf(n % m ? " %d\n" : "\n", begin + n % m - 1);   //����Ĵ�������̫���� 
    }
    return 0;
}
