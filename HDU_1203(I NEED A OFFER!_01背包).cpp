// http://acm.hdu.edu.cn/showproblem.php?pid=1203
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct{
    int money;
    double prob;
}School;

School school[10005];
double dp[10005];

int main()
{
    int i,j,n,m;
    double minmium;
    scanf("%d %d",&n,&m);
    while(n!=0 || m!=0)
    {
        memset(school,0,sizeof(school));

        for(i=0;i<m;i++)
        {
            scanf("%d %lf",&school[i].money,&school[i].prob);
            school[i].prob = 1.0 - school[i].prob;
        }

        minmium = 1000;
        for(j=n;j>=0;j--)
        {
            dp[j] = 1;
        }
        for(i=0;i<m;i++)
        {
            for(j=n;j>=school[i].money;j--)
            {
                dp[j] = min(dp[j],dp[j-school[i].money]*school[i].prob);
            }
        }
        minmium = 1-dp[n];
        minmium *= 100;
        printf("%.1lf%%\n",minmium);
        scanf("%d %d",&n,&m);
    }
    return 0;
}
