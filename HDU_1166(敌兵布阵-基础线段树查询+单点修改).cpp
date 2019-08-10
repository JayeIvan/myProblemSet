// http://acm.hdu.edu.cn/showproblem.php?pid=1166
// 线段树,查询,单点修改
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

const int maxn = 50005;
int segtree[4*maxn];

// 收集子节点的和
void Pushup(int k)
{
    segtree[k] = segtree[k*2]+segtree[k*2+1];
}

// k为当前节点的编号
void build(int k,int l,int r)
{
    // printf("k:%d  l:%d  r:%d\n",k,l,r);
    if(l==r)
    {
        scanf("%d",&segtree[k]);
        // printf("k=%d : %d\n",k,segtree[k]);
        return;
    }
    int m = (l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    // k的两个子节点确定后更新k的信息
    Pushup(k);
}
// 在整个区间二分查询
int query(int ql,int qr,int k,int l,int r)
{
    int ans = 0;
    if(ql<=l&&r<=qr)
    {
        return segtree[k];
    }
    int m = (l+r)/2;
    // 如果ql在左区间，在左区间查询ql
    if(ql<=m)
        ans += query(ql,qr,k*2,l,m);
    // 如果qr在右区间，在右区间查询qr
    if(qr>m)
        ans += query(ql,qr,k*2+1,m+1,r);
    return ans;
}

void update(int id,int val,int k,int l,int r)
{
    if(l==r)
    {
        segtree[k] += val;
        return;
    }
    int m = (l+r)/2;
    // 二分查询id
    if(id<=m) update(id,val,k*2,l,m);
    else update(id,val,k*2+1,m+1,r);
    // k的两个子节点确定后更新k的信息
    Pushup(k);
}

int main ()
{
    int t,m,ca,x,v;
    char str[10];
    cin >> t;
    ca = 1;
    while (t--)
    {
        cin >> m;
        build(1,1,m);
        printf("Case %d:\n",ca++);
        while (cin >> str)
        {
            if(str[0]=='E') break;
            scanf("%d %d",&x,&v);
            if(str[0]=='Q')
            {
                int tmp = query(x,v,1,1,m);
                printf("%d\n",tmp);
            }
            if(str[0]=='A')
                update(x,v,1,1,m);
            if(str[0]=='S')
                update(x,-v,1,1,m);
        }

    }

    return 0;
}
