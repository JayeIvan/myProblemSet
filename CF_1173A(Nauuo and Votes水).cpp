// https://codeforces.com/problemset/problem/1173/A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define inf 0x3f3f3f3f
typedef long long  ll;

using namespace std;

int main()
{
    int x,y,z,n;
    while(cin >> x >> y >> z)
    {
        if(x>(y+z))
            printf("+\n");
        else if(y>(x+z))
            printf("-\n");
        else if(x==y && z==0)
            printf("0\n");
        else if(x<=(y+z) || y<=(x+z))
            printf("?\n");
    }
    return 0;
}
