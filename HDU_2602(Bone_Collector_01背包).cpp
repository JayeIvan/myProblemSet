// http://acm.hdu.edu.cn/showproblem.php?pid=2602
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct{
    int value;
    int cost;
}Bone;

int t;
int num,volume;
Bone bones[1000];

int i,j,dp[1000];

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> num >> volume;
        for(i=1;i<=num;i++)
            scanf("%d",&bones[i].value);
        for(i=1;i<=num;i++)
            scanf("%d",&bones[i].cost);

        memset(dp,0,sizeof(dp));
        for(i=1;i<=num;i++)
        {
            // 空间优化为一维，从Volume到0，倒着迭代计算
            for(j=volume;j>=bones[i].cost;j--)
            {
                dp[j] = max(dp[j],dp[j-bones[i].cost]+bones[i].value);
            }
        }
        cout << dp[volume] << endl;
    }
    return 0;
}
