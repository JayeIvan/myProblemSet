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

const int maxn = 200005;
int segtree[4*maxn],ans;

void Pushup(int k)
{
    segtree[k] = max(segtree[k*2],segtree[k*2+1]);
}

void build(int k,int l,int r)
{
    if(l==r)
    {
        scanf("%d",&segtree[k]);
        return;
    }
    int m = (l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    Pushup(k);
}

void update(int id,int v,int k,int l,int r)
{
    if(l==r)
    {
        segtree[k] = v;
        return;
    }
    int m = (l+r)/2;
    // 二分查询id
    if(id<=m) update(id,v,k*2,l,m);
    else update(id,v,k*2+1,m+1,r);
    Pushup(k);
}


int query(int ql,int qr,int k,int l,int r)
{
    if(ql<=l&&r<=qr)
    {
        return segtree[k];
    }
    int m = (l+r)/2;
    // 如果ql在左区间，在左区间查询ql
    if(ql<=m) ans = max(ans,query(ql,qr,k*2,l,m));
    // 如果qr在右区间，在右区间查询qr
    if(m<qr) ans = max(ans,query(ql,qr,k*2+1,m+1,r));
    return ans;
}

int main ()
{
    int m,n,x,v;
    char c;
    while (cin >> m >> n)
    {
        build(1,1,m);
        while(n--)
        {
            ans = 0;
            cin >> c >> x >> v;
            if(c=='U')
                update(x,v,1,1,m);
            if(c=='Q')
                cout << query(x,v,1,1,m) << endl;
        }
    }
    
    return 0;
}