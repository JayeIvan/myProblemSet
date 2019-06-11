// http://acm.hdu.edu.cn/showproblem.php?pid=1312
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

int n,m,sx,sy,graph[25][25],dir[4][2]={-1,0,1,0,0,-1,0,1},cnt;
int vis[25][25];

struct vertex
{
    int x,y;
    vertex(int x,int y):x(x),y(y){}
};

void bfs(int x,int y)
{
    queue<vertex> Q;
    // 头节点（人所在的位置）入队
    Q.push(vertex(sx,sy));
    vis[sx][sy] = 1;
    while(!Q.empty())
    {
        cnt++;
        // 队头元素出队，弹出
        vertex v = Q.front();
        Q.pop();
        // 依次访问它的相邻(四个方向上的)节点
        for(int i=0;i<4;i++)
        {
            int x = v.x+dir[i][0];
            int y = v.y+dir[i][1];
            if(x<0 || y<0 || x>m || y>n || vis[x][y] || !graph[x][y])
                continue;
            vis[x][y] = 1;
            Q.push(vertex(x,y));
        }
    }
}

int main()
{
    string str;
    int i,j;
    cin >> n >> m;
    while(m && n)
    {
        memset(graph,0,sizeof(graph));
        memset(vis,0,sizeof(vis));
        cnt = 0;
        for(i=0;i<m;i++)
        {
            cin >> str;
            for(j=0;j<n;j++)
            {
                if(str[j]=='.')
                    graph[i][j] = 1;
                if(str[j]=='@')
                    sx = i,sy = j;
            }
        }
        bfs(sx,sy);
        printf("%d\n",cnt);
        cin >> n >> m;
    }

    return 0;
}


