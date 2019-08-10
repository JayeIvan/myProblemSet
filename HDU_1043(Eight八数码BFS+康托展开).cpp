// http://acm.hdu.edu.cn/showproblem.php?pid=1043
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

const ll maxn = 370000;
typedef struct
{
    int s[10];
    int loc;
    int ct;
}node;
node cur,t,nex;
int fac[10],flag;

// 逆向搜索，记录下来的路径是和正向相反的，就需要调整过来d[5] = "lrdu"
int dir[4][2] = {0,1, 0,-1, -1,0, 1,0};// r l u d
char d[5] = "lrdu";

int vis[maxn];
string path[maxn];

void init()
{
    memset(vis,0,sizeof(vis));

    fac[0] = 1;
    fac[1] = 1;
    for(int i=2;i<10;i++)
        fac[i] = fac[i-1]*i;
}

int cantor(int a[])
{
    int sum = 0;
    for(int i=0;i<8;i++)
    {
        int m = 0;
        for(int j=i+1;j<9;j++)
            if(a[j]<a[i])
                m++;
        sum += m*fac[9-i-1];
    }
    return sum+1;
}

void bfs()
{
    queue<node> q;

    for(int i=0;i<9;++i)
        cur.s[i] = i;
    cur.ct = cantor(cur.s);
    cur.loc = 8;
    q.push(cur);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = cur.loc/3 + dir[i][0];
            int y = cur.loc%3 + dir[i][1];

            if(x<0 || x>2 || y<0 || y>2) continue;

            nex = cur;
            nex.loc = x*3 + y;
            nex.s[cur.loc] = nex.s[nex.loc];
            nex.s[nex.loc] = 9;

            nex.ct = cantor(nex.s);
            if(!vis[nex.ct])
            {
                vis[nex.ct] = 1;
                path[nex.ct] = d[i]+path[cur.ct];
                q.push(nex);
            }
        }
    }

}

int main()
{
    char s[2];
    flag = 0;
    init();

    for(int i=0;i<9;i++)
    {
        scanf("%s",s);
        if(s[0]=='x')
        {
            t.s[i] = 9;
            t.loc = i;
        }
        else
            t.s[i] = s[0]-'0';
    }
    t.ct = cantor(t.s);
    bfs();
    if(vis[t.ct]) cout << path[t.ct] << endl;
    else cout << "unsolvable" << endl;

    return 0;
}