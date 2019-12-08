#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>
#define inf 1000000000
#define ll long long

// hdu1025

using namespace std;

typedef struct
{
    int p,r;
}City;
City cities[500005];
int rcd[500005],lrcd[500005];

int main()
{
    int n,cnt,res;
    cnt = 0;
    while(scanf("%d",&n)!=EOF)
    {
        cnt++;
        for(int i=0;i<n;i++)
            scanf("%d %d",&cities[i].r,&cities[i].p);

        memset(rcd,0,sizeof(rcd));
        rcd[0] = 1;
        res = 0;
        for(int i=0;i<n;i++)
        {
            rcd[i] = 1;
            sort(lrcd,lrcd+cities[i].p);
            for(int j=0;j<i;j++)
            {
                if() rcd[i] = max(lrcd[cities[i].p-1]+1,rcd[i]);
            }
            memcpy(lrcd,rcd,sizeof(rcd));
            res = max(res,rcd[i]);
        }

        printf("Case %d:\n",cnt);
        printf("My king, at most %d road can be built.\n\n",res);
    }
        return 0;
}


/*  dp,but...TLE
typedef struct
{
    int p,r;
}City;
City cities[500005];
int rcd[500005];

bool cmp(City a,City b)
{
    return a.r < b.r;
}

int main()
{
    int n,cnt,res;
    cnt = 0;
    while(scanf("%d",&n)!=EOF)
    {
        cnt++;
        for(int i=0;i<n;i++)
            scanf("%d %d",&cities[i].r,&cities[i].p);

        memset(rcd,0,sizeof(rcd));
        rcd[0] = 1;
        res = 0;
        for(int i=0;i<n;i++)
        {
            rcd[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(cities[j].p<cities[i].p) rcd[i] = max(rcd[j]+1,rcd[i]);
            }
            res = max(res,rcd[i]);
        }

        printf("Case %d:\n",cnt);
        printf("My king, at most %d road can be built.\n\n",res);
    }
        return 0;
}

*/
