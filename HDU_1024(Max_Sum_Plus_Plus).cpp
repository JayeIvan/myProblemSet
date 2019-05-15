// http://acm.hdu.edu.cn/showproblem.php?pid=1024
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long int xmax(long long int a,long long int b){
    if(a>b) b=a;
    return b;
}

int main(){
    int m,n,i,j;
    long long int M,*num,*dp,*mmax;
    // n个数，划为m组
    while(scanf("%d %d",&m,&n)!=EOF){
        num = (long long int*)calloc((n+1),sizeof(long long int));
        // dp用于存储当前状态j对应的最大值
        dp = (long long int*)calloc((n+1),sizeof(long long int));
        // mmax用于存储上一个状态时，每个num[j]对应的最大值
        mmax = (long long int*)calloc((n+1),sizeof(long long int));

        for(i=1;i<=n;i++) scanf("%lld",&num[i]);

        // 把第j个数分到他前面一组，或者找前i-1组中最大的，然后j单独分一组
        for(i=1;i<=m;i++){
            M=-10000000000;
            for(j=i;j<=n;j++){
                // 状态转移公式
                dp[j] = xmax(dp[j-1],mmax[j-1])+num[j];
                // 更新j-1的最大值，然后再更新M（当前状态下j对应的最大值）
                mmax[j-1] = M;
                M = xmax(dp[j],M);
            }
        }
        // 最后最大的结果是M
        printf("%lld\n",M);

        free(dp);
        free(num);
        free(mmax);
    }
    return 0;
}

