// http://poj.org/problem?id=3984
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

int maze[5][5],vis[5][5],pindex[100],cnt;
int dir[2][4] = {0,-1,0,1,-1,0,1,0};
typedef struct
{
    int x,y,last;
}Point;
Point t;
queue<Point> q;
vector<Point> path;

void bfs()
{
    // 从终点往起点搜索，便于记录路径
    Point a;
    a.x = 4;
    a.y = 4;
    vis[4][4] = 1;
    a.last = -1;
    q.push(a);
    while(!q.empty())
    {
        t = q.front();
        if(t.x==0 && t.y==0) break;
        // 出队同时放入vector中保存下来
        path.push_back(t);
        q.pop();
        Point next;
        // last记录下该节点的前驱节点在vector中的序号
        next.last = path.size()-1;
        for(int i=0;i<4;i++)
        {
            next.x = t.x + dir[0][i];
            next.y = t.y + dir[1][i];
            if(next.x<0||next.x>4||next.y<0||next.y>4) continue;
            if(!vis[next.x][next.y] && !maze[next.x][next.y])
            {
                q.push(next);
                vis[next.x][next.y] = 1;
            }
        }
    }
    int past = t.last;
    cnt = 0;
    while(past!=-1)
    {
        // printf("%d\n",past);
        pindex[cnt++] = past;
        past = path[past].last;
    }
}

int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }

    memset(vis,0,sizeof(vis));
    bfs();
    printf("(0, 0)\n");
    for(int i=0;i<cnt;i++)
    {
        int c = pindex[i];
        // printf("%d\n",c);
        printf("(%d, %d)\n",path[c].x,path[c].y);
    }

    return 0;
}
