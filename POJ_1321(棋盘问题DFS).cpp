// http://poj.org/problem?id=1321
// DFS
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

char chs[10][10]; // 记录棋盘情况，有哪些位置可放棋子
int vis[10];      // 记录哪些列放了棋子
int n,k,cnt;
ll res=0;

void dfs(int row)
{
    if(cnt==k)
    {
        res++;
        return;
    }
    if(row>=n)
        return;
    // 因为两个棋子不能放在同一列，因此先遍历行，再检查该行的各个列
    for(int i=0;i<n;i++)
    {
        if(chs[row][i]=='#' && !vis[i])
        {
            cnt++;
            vis[i] = 1;
            dfs(row+1);
            vis[i] = 0;
            cnt--;
        }
    }
    dfs(row+1);
}

int main()
{
    cin >> n >> k;
    while(n!=-1&&k!=-1)
    {
        for(int i=0;i<n;i++)
            scanf("%s",&chs[i]);
        memset(vis,0,sizeof(0));
        cnt = 0;
        res = 0;
        dfs(0);
        printf("%lld\n",res);
        cin >> n >> k;
    }
    return 0;
}
