#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include<string.h>
#include <map>

using namespace std;

int index[200005];

int main()
{
    int n,t;
    cin >> t;
    while (t--)
    {
        memset(index,0,sizeof(index));

        cin >> n;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            index[tmp] = i;
        }

        int l = index[1];
        int r = index[1];
        for(int i=1;i<=n;i++)
        {
            l = min(index[i],l);
            r = max(index[i],r);
            if(r-l+1 == i) 
                printf("1");
            else 
                printf("0");
        }
        printf("\n");
    }
    
    return 0;
}
