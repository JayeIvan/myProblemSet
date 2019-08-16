// http://poj.org/problem?id=3468
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

const int maxn=100005;

struct node
{
    int l,r;
    ll sum,mark;
}tree[4*maxn];
ll a[4*maxn];


void build(int k,int l,int r)
{
    tree[k].l = l;
    tree[k].r = r;
    tree[k].mark = 0;
    if(l==r)
    {
        // 注意输入数据超过32位整数
        scanf("%lld",&tree[k].sum);
        return;
    }
    int m = (l+r)/2;
    build(2*k,l,m);
    build(2*k+1,m+1,r);
    tree[k].sum = tree[2*k].sum + tree[2*k+1].sum;
}

void update(int k,int ql,int qr,ll v)
{
    if(ql==tree[k].l && tree[k].r==qr)
    {
        tree[k].mark += v;
        return;
    }
    // 相当于pushup,将路过的节点都update,不再mark
    tree[k].sum += (ll)(qr-ql+1)*v;

    int m = (tree[k].l+tree[k].r)/2;
    if(qr<=m)
        update(2*k,ql,qr,v);
    else if(ql>m)
        update(2*k+1,ql,qr,v);
    else
    {
        // 如果更新区间不被左右子区间包含，将更新区间二分
        update(2*k,ql,m,v);
        update(2*k+1,m+1,qr,v);
    }
}

ll query(int k,int ql,int qr)
{
    if(ql==tree[k].l && tree[k].r==qr)
    {
        return tree[k].sum + tree[k].mark*(ll)(qr-ql+1);
    }
    // 延迟标记下移
    if(tree[k].mark!=0)
    {
        tree[k].sum += tree[k].mark*(ll)(tree[k].r - tree[k].l + 1);

        tree[2*k].mark += tree[k].mark;
        tree[2*k+1].mark += tree[k].mark;
        tree[k].mark = 0;
    }

    int m = (tree[k].l+tree[k].r)/2;
    if(qr<=m)
        return query(2*k,ql,qr);
    else if(ql>m)
        return query(2*k+1,ql,qr);
    // 如果查询区间不被左右子区间包含，将查询区间二分
    else
        return query(2*k,ql,m)+query(2*k+1,m+1,qr);
}

int main()
{
    int m,n,x,y;
    ll v,ans;
    while (cin >> n >> m)
    {
        build(1,1,n);
        while (m--)
        {
            char ch[10];
            scanf("%s",ch);
            if(ch[0]=='C')
            {
                cin >> x >> y >> v;
                update(1,x,y,v);
            }
            else if(ch[0]=='Q')
            {
                cin >> x >> y;
                ans = query(1,x,y);
                cout << ans << endl;
            }
        }
    }  
    return 0;
}