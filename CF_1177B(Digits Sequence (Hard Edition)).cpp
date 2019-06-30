#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define inf 0x3f3f3f3f
typedef long long  ll;

using namespace std;

int seq[10005];

int main()
{
    int m,n,i,j,k,tmp[10];
    j = 0;
    for(i=1;i<10001;)
    {
        n = j++;
        m = 0;
        while(n)
        {
            tmp[m++] = n%10;
            n /= 10;
        }
        for(int h=m-1;h>=0;h--) seq[i++] = tmp[h];
    }
    //for(i=1;i<100;i++) cout << seq[i];
    while(cin >> k)
    {
        printf("%d\n",seq[k]);
    }

    return 0;
}
