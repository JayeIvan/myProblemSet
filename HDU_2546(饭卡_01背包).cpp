// http://acm.hdu.edu.cn/showproblem.php?pid=2546
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int food[1005];
int dp[1005];

int main()
{
    int i,j,n,m,maxmium;
    scanf("%d",&n);
    while(n!=0)
    {
        memset(dp,0,sizeof(dp));
        memset(food,0,sizeof(food));

        for(i=0;i<n;i++)
        {
            scanf("%d",&food[i]);
        }

        sort(food,food+n);

        // ������������
        scanf("%d",&m);


        if(m<5) printf("%d\n",m);
        else
        {
            maxmium = 0;
            // ̰�ģ���5Ԫȥ�����Ĳˣ�ʣ�µ�ͬ01����
            for(i=0;i<n-1;i++)
            {
                for(j=m-5;j>=0;j--)
                {
                    if(j>=food[i])
                        dp[j] = max(dp[j-food[i]]+food[i],dp[j]);
                    else
                        dp[j] = dp[j-1];
                    maxmium = max(maxmium,dp[j]);
                }
            }
            printf("%d\n",m-maxmium-food[n-1]);
        }
        scanf("%d",&n);
    }
    return 0;
}

