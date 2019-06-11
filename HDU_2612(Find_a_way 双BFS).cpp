// http://acm.hdu.edu.cn/showproblem.php?pid=2612
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define inf 0x3f3f3f3f
typedef long long  ll;

using namespace std;

int graph[205][205],vis[205][205],resy[205][205],resm[205][205];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int m,n,yx,yy,mx,my,ans;

struct vertex
{
    int x,y,depth;
    vertex(int x,int y,int d):x(x),y(y),depth(d){}
};

void bfs(int sx,int sy,int res[205][205])
{
    memset(vis,0,sizeof(vis));
    queue<vertex> Q;
    Q.push(vertex(sx,sy,0));
    vis[sx][sy] = 0;
    while(!Q.empty())
    {
        vertex v = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int x = v.x+dir[i][0];
            int y = v.y+dir[i][1];
            if(x<0 || y<0 || x>n || y>m || vis[x][y] || !graph[x][y]) continue;
            vis[x][y] = 1;
            if(graph[x][y]==2)
                res[x][y] = v.depth+1;
            Q.push(vertex(x,y,v.depth+1));
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    int i,j;
    string c;
    while(cin >> n >> m)
    {
        memset(graph,0,sizeof(graph));
        memset(vis,0,sizeof(vis));
        memset(resy,0,sizeof(resy));
        memset(resm,0,sizeof(resm));
        for(i=0;i<n;i++)
        {
            cin >> c;
            for(j=0;j<m;j++)
            {
                if(c[j]=='Y')
                {
                    yx = i;
                    yy = j;
                }
                else if(c[j]=='M')
                {
                    mx = i;
                    my = j;
                }
                else if(c[j]=='.')
                {
                    graph[i][j] = 1;
                }
                else if(c[j]=='@')
                {
                    graph[i][j] = 2;
                }
            }
        }

        bfs(yx,yy,resy);
        bfs(mx,my,resm);

        ans = inf;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(graph[i][j]==2 && resy[i][j]!=0)
                    ans = min(ans,resy[i][j]+resm[i][j]);
        }
        printf("%d\n",ans*11);

    }
    return 0;
}
