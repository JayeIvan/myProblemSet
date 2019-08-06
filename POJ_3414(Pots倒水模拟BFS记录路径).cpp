// http://poj.org/problem?id=3414
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
    // step记录操作，num记录上次操作在vector中的序号
    int a,b,step,num;
}Node;
Node x,t,c;
int a,b,m,cnt,vis[1005][1005],flag;
int path[100];
queue<Node> q;
vector<Node> v;

void bfs()
{
    Node x;
    x.a = 0;
    x.b = 0;
    x.step = 0;
    x.num = 0;
    q.push(x);
    vis[0][0] = 1;
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if(t.a==m || t.b==m)
        {
            flag = 1;
            break;
        }
        v.push_back(t);
        c.num = v.size()-1;
        // 第一种step = 1，把a倒满
        if(t.a<a)
        {
            c.a = a;
            c.b = t.b;
            c.step = 1;
            if(!vis[c.a][c.b])
            {
                q.push(c);
                vis[c.a][c.b] = 1;
            }
        }
        // 第二种step = 2，把a倒空
        if(t.a>0)
        {
            c.a = 0;
            c.b = t.b;
            c.step = 2;
            if(!vis[c.a][c.b])
            {
                q.push(c);
                vis[c.a][c.b] = 1;
            }
        }
        // 第三种step = 3，把b倒满
        if(t.b<b)
        {
            c.a = t.a;
            c.b = b;
            c.step = 3;
            if(!vis[c.a][c.b])
            {
                q.push(c);
                vis[c.a][c.b] = 1;
            }
        }
        // 第四种step = 4，把b倒空
        if(t.b>0)
        {
            c.a = t.a;
            c.b = 0;
            c.step = 4;
            if(!vis[c.a][c.b])
            {
                q.push(c);
                vis[c.a][c.b] = 1;
            }
        }
        // 第五种a倒入b
        if(t.a>0 && t.b<b)
        {
            if(t.a>(b-t.b))
            {
                c.a = t.a - (b-t.b);
                c.b = b;
                c.step = 5;
                if(!vis[c.a][c.b])
                {
                    q.push(c);
                    vis[c.a][c.b] = 1;
                }
            }
            else
            {
                c.a = 0;
                c.b = t.a + t.b;
                c.step = 5;
                if(!vis[c.a][c.b])
                {
                    q.push(c);
                    vis[c.a][c.b] = 1;
                }
            }
        }

        // 第六种b倒入a
        if(t.b>0 && t.a<a)
        {
            if(t.b>(a-t.a))
            {
                c.a = a;
                c.b = t.b - (a-t.a);
                c.step = 6;
                if(!vis[c.a][c.b])
                {
                    q.push(c);
                    vis[c.a][c.b] = 1;
                }
            }
            else
            {
                c.a = t.a + t.b;
                c.b = 0;
                c.step = 6;
                if(!vis[c.a][c.b])
                {
                    q.push(c);
                    vis[c.a][c.b] = 1;
                }
            }
        }
    }

    // 回溯路径
    int last = t.num;
    path[0] = t.step;
    cnt = 1;
    while (last!=0)
    {
        path[cnt++] = v[last].step;
        last = v[last].num;
    }
}

int main()
{
    while (cin >> a >> b >> m)
    {
        flag = 0;
        memset(vis,0,sizeof(vis));
        bfs();
        if(flag)
        {
            printf("%d\n",cnt);
            while(cnt--)
            {
                if(path[cnt]==1) printf("FILL(1)\n");
                if(path[cnt]==2) printf("DROP(1)\n");
                if(path[cnt]==3) printf("FILL(2)\n");
                if(path[cnt]==4) printf("DROP(2)\n");
                if(path[cnt]==5) printf("POUR(1,2)\n");
                if(path[cnt]==6) printf("POUR(2,1)\n");
            }
        }
        else
        {
            printf("impossible\n");
        }

    }
    return 0;
}
