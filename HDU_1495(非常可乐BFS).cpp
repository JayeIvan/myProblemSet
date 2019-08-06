// http://acm.hdu.edu.cn/showproblem.php?pid=1495
// BFS
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

typedef struct
{
    int s,n,m,step;
}Cup;
queue<Cup> q;
Cup x,t,cur;
int vis[105][105][105];
int s,n,m,ans;


void bfs()
{
    x.s = s;
    x.n = 0;
    x.m = 0;
    x.step = 0;
    vis[s][0][0] = 0;
    q.push(x);
    while(!q.empty())
    {
        t = q.front();
        cur = t;
        q.pop();
        cur.step = t.step+1;
        if((t.s==s/2 && t.n==s/2)||(t.s==s/2 && t.m==s/2)||(t.m==s/2 && t.n==s/2))
        {
            ans = t.step;
            break;
        }

        // s����n
        if(t.s>0 && t.n<n)
        {
            cur.m = t.m;
            // �ܵ���
            if(t.s>(n-t.n)&&t.n<n)
            {
                cur.s = t.s - (n-t.n);
                cur.n = n;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
            else // ���ܵ���n,����s
            {
                cur.s = 0;
                cur.n = t.n + t.s;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
        }

        // s����m
        if(t.s>0 && t.m<m)
        {
            cur.n = t.n;
            // �ܵ���m
            if(t.s>(m-t.m)&&t.m<m)
            {
                cur.s = t.s - (m-t.m);
                cur.m = m;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
            else
            {
                cur.s = 0;
                cur.m = t.m + t.s;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
        }

        // n����m
        if(t.n>0 && t.m<m)
        {
            cur.s = t.s;
            // �ܵ���m
            if(t.n>(m-t.m)&&t.m<m)
            {
                cur.n = t.n - (m-t.m);
                cur.m = m;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
            else
            {
                cur.n = 0;
                cur.m = t.m + t.n;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
        }

        // n����s,�����Լ�
        if(t.n>0)
        {
            cur.m = t.m;
            cur.s = t.s + t.n;
            cur.n = 0;
            if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
            vis[cur.s][cur.n][cur.m] = 1;
        }

        // m����n
        if(t.m>0 && t.n<n)
        {
            cur.s = t.s;
            // �ܵ���n
            if(t.m>(n-t.n)&&t.n<n)
            {
                cur.m = t.m - (n-t.n);
                cur.n = n;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
            else
            {
                cur.m = 0;
                cur.n = t.n + t.m;
                if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
                vis[cur.s][cur.n][cur.m] = 1;
            }
        }

        // m����s
        if(t.m>0)
        {
            cur.n = t.n;
            cur.s = t.s + t.m;
            cur.m = 0;
            if(!vis[cur.s][cur.n][cur.m]) q.push(cur);
            vis[cur.s][cur.n][cur.m] = 1;
        }
    }
}

int main()
{
    cin >> s >> n >> m;
    while(s||n||m)
    {
        memset(vis,0,sizeof(vis));
        // ��ն���
        while(!q.empty()) q.pop();
        if(s%2==1)
            printf("NO\n");
        else
        {
            ans = -1;
            bfs();
            if(ans==-1) printf("NO\n");
            else printf("%d\n",ans);
        }
        cin >> s >> n >> m;
    }

    return 0;
}
