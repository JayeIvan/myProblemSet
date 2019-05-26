#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct
{
  float prob;
  int money;
}Bank;

bool cmp(Bank a,Bank b)
{
    return a.money < b.money;
}

Bank bank[105];
float dp[100005];

int main()
{
    int i,j,t,num,sum,V;
    float pro,prob;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(bank,0,sizeof(bank));
        cin >> pro >> num;
        pro = 1.0-pro;
        V = 0;
        for(i=0;i<num;i++)
        {
            scanf("%d %f",&bank[i].money,&bank[i].prob);
            bank[i].prob = 1.0 - bank[i].prob;
            V += bank[i].money;
        }

        dp[0] = 1;
        sum = 0;

        sort(bank,bank+num,cmp);

        for(i=0;i<=num;i++)
        {
            for(j=V;j>=bank[i].money;j--)
            {
                dp[j] = max(dp[j],dp[j-bank[i].money]*bank[i].prob);
            }
        }

        for(i=V;i>=0;i--)
        {
            if(dp[i]>=pro)
            {
                cout << i << endl;
                break;
            }
        }

    }
    return 0;
}
