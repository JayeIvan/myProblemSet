// http://poj.org/problem?id=3278
// BFS+��֦
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

int vis[100005];

int main()
{
    int m,n,k,x;
    queue<int> q;
    while(cin >> n >> k)
    {
        memset(vis,0,sizeof(vis));
        q.push(n);
        while(!q.empty())
        {
            x = q.front();
            q.pop();
            // �����յ�
            if(x==k) break;
            // x>kʱ��ֻ��-1�Ĵ���
            if(x>0 && !vis[x-1])
            {
                q.push(x-1);
                vis[x-1]=vis[x]+1;
            }
            if(x<k && !vis[x+1])
            {
                q.push(x+1);
                vis[x+1]+=vis[x]+1;
            }
            if(x*2<100005 && !vis[x*2])
            {
                q.push(2*x);
                vis[2*x]+=vis[x]+1;
            }
        }
        printf("%d\n",vis[k]);
    }
    return 0;
}
