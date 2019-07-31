// http://poj.org/problem?id=1426
// BFS。。。RE(不知道什么原因一直RE)
// 用符合二叉树的特点，因此用数组下标按照二叉树的方式来存
// 从高位到低位搜索，余数=（高位余数*10+本位的数字）%n
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <math.h>
#include <iostream>
#define INF 1e9
#define eps 1e-6
#define ll long long
const int maxn=1e5;

using namespace std;

int n;
int dp[maxn];
vector<int> res;

int main()
{
    while(cin >> n && n)
    {
        int i;
        memset(dp,0,sizeof(dp));
        dp[1] = 1%n;

        for(i=1;i<maxn;i++)
        {
            dp[i*2] = dp[i]*10%n;
            dp[i*2+1] = (dp[i]*10+1)%n;
            // printf("%d : %d   %d : %d\n",i*2,dp[i*2],i*2+1,dp[i*2+1]);
            if(dp[i*2]==0)
            {
                i = i*2;
                break;
            }
            if(dp[i*2+1]==0)
            {
                i = i*2+1;
                break;
            }
        }

        res.clear();
        while(i)
        {
            res.push_back(i%2);
            i /= 2;
        }
        for(int h=res.size()-1;h>=0;h--)
            printf("%d",res[h]);
        printf("\n");
    }
    return 0;
}
