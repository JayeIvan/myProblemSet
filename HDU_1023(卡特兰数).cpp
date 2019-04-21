//http://acm.hdu.edu.cn/showproblem.php?pid=1023

#include <iostream>
#include <cstdio>
#define MAX 105

using namespace std;

int catalan[MAX][MAX];

void Catalan_num(){
    catalan[0][0]=1;
    catalan[1][0]=1;
    catalan[0][1]=1;
    catalan[1][1]=1;

    int i,j,temp,t;
    // len记录的是h(n-1)的位数
    int len = 1;

    for(i=2;i<=100;i++){
        // 记录进位
        temp=0;
        for(j=1;j<=len;j++){
            t = catalan[i-1][j]*(4*i-2)+temp;
            catalan[i][j]=t%10;
            temp = t/10;
        }
        //最后一位计算后仍需要进位
        while(temp){
            catalan[i][++len]=temp%10;
            temp/=10;
        }
        // 继续计算除以(n+1)，从高位到低位
        // 取整除的部分，余数*10加到下一位上
        for(j=len;j>=1;j--){
            t = catalan[i][j]+temp*10;
            catalan[i][j] = t/(i+1);
            temp = t%(i+1);
        }
        while(!catalan[i][len]){
            len--;
        }
        catalan[i][0] = len;
    }
}

int main()
{
    int n;
    // 从1开始记录，0用于存放位数（h(n)的长度）
    Catalan_num();
    while(scanf("%d",&n)!=EOF){
        for(int i=catalan[n][0];i>0;i--){
            if(catalan[n][i]>=0)printf("%d",catalan[n][i]);
        }
        printf("\n");
    }
    return 0;
}