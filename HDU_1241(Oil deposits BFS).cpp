// http://acm.hdu.edu.cn/showproblem.php?pid=1241
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

char depos[100][100];
int vis[100][100];
int m,n;
int dir[2][8] = {0,-1,0,1,-1,1,-1,1, -1,0,1,0,-1,-1,1,1};
queue<pair<int,int> > q;

void bfs(int a,int b)
{
    pair<int,int> x = make_pair(a,b);
    q.push(x);

    while (!q.empty())
    {
        pair<int,int> t = q.front();
        q.pop();

        pair<int,int> cur;
        for(int i=0;i<8;i++)
        {
            int x = t.first + dir[0][i];
            int y = t.second + dir[1][i];
            if(x<0||y<0||x>=n||y>=m||vis[x][y]||depos[x][y]=='*') continue;
            cur = make_pair(x,y);
            q.push(cur);
            vis[x][y] = vis[t.first][t.second];
        }
    }
    
}

int main()
{
    while (cin >> n >> m && m && n)
    {
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < n; i++)
           scanf("%s",depos[i]);
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(depos[i][j]=='@' && !vis[i][j])
                {
                    vis[i][j] = ++ans;
                    bfs(i,j);
                }
            }
        }    
        printf("%d\n",ans);
    }
    
    
    return 0;
}
