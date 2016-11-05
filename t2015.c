#include <stdio.h>

int main(void)
{
    int i, n, m, begin, state;
    //核心是等差数列的求和，找出其中的规律，这一点自己很缺乏！覆盖的思维，转态的思维！ 
    while (scanf("%d%d", &n, &m) != EOF){
        begin= 2,state= 0;
        for (i = 0 ; i < n / m ; i++) {
            printf(state++ ? " %d" : "%d", begin + m - 1);  //这个“？：”真是用的神乎其神！ 
            begin += m * 2;
        }
        printf(n % m ? " %d\n" : "\n", begin + n % m - 1);   //这里的处理真是太妙了 
    }
    return 0;
}
