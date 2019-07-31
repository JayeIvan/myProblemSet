// http://poj.org/problem?id=3126
// BFS
// 在加vis之前T了，加vis标记以后AC；
// 理解为不会从一个数折回到另一个已访问过的数
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

using namespace std;

const int maxn=1e5;
int prime[100000];
int vis[100000];
typedef struct
{
    int s;
    string num;
}Brand;

Brand n,m;

bool isPrime(long long n)
{
    if(n<=3)
        return n>1;
    if(n%6!=1 && n%6!=5)
        return false;
    long long s = sqrt(double(n));
    for(long long i=5;i<=s;i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}

int main()
{
    int t;
    queue<Brand> q;
    memset(prime,0,sizeof(prime));
    for(int i=1000;i<=9999;i++)
        if(isPrime(i)) prime[i] = 1;
    cin >> t;
    while(t--)
    {
        int ans = 100000;
        cin >> n.num >> m.num;
        if(n.num>m.num) swap(n.num,m.num);
        // 第二个用来记录从n到该素数走了几步
        n.s = 0;
        m.s = 0;

        memset(vis,0,sizeof(vis));

        q.push(n);
        while(!q.empty())
        {
            if(n.num==m.num)
            {
                ans = 0;
                break;
            }
            Brand tmp = q.front();
            q.pop();
            // 到达目标位
            if(tmp.num==m.num)
            {
                ans = min(ans,tmp.s);
                continue;
            }

            for(int i=0;i<4;i++)
            {
                for(int j=0;j<10;j++)
                {
                    // 把千位改成0没有意义，跳过
                    if((i==0&&j==0) || tmp.s>=ans) continue;

                    Brand cur;
                    cur.num = tmp.num;
                    cur.s = tmp.s+1;

                    if(cur.s>=ans) continue;

                    // 算出改变后的数
                    cur.num[i] = j+'0';
                    if(cur.num==tmp.num) continue;
                    int a = (cur.num[0]-'0')*1000+(cur.num[1]-'0')*100+(cur.num[2]-'0')*10+(cur.num[3]-'0');
                    // 如果是素数就进队
                    if(prime[a] && !vis[a])
                    {
                        q.push(cur);
                        vis[a] = 1;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
