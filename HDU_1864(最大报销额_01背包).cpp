// http://acm.hdu.edu.cn/showproblem.php?pid=1864
#include <iostream>
#include <strstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iomanip>
#include <map>
#include <cstring>
#include <algorithm>
#define EPS 1e-6

using namespace std;

double cost[35];
double dp[35];

double stringToDouble(const string &s)
{
	double val;
	strstream ss;
	ss << s;
	ss >> val;
	return val;
}

int main()
{
    int i,j,n,m;
    double v,A,B,C;
    string str;
    cin >> v >> n;
    while(n!=0)
    {
        memset(cost,0,sizeof(cost));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            cin >> m;
            A = B = C = 0;
            while(m--)
            {
                cin >> str;
                if(str[0]=='A')
                {
                    str = str.erase(0,2);
                    A += stringToDouble(str);
                }
                else if(str[0]=='B')
                {
                    str = str.erase(0,2);
                    B += stringToDouble(str);
                }
                else if(str[0]=='C')
                {
                    str = str.erase(0,2);
                    C += stringToDouble(str);
                }
                else
                {
                    cost[i] = 0;
                    continue;
                }
                cost[i] = A + B + C;
                if(A > 600 || B > 600 || C > 600 || cost[i] > 1000) cost[i] = 0;
            }
        }

        double mm = 0;
        for(i=0;i<n;i++)
        {
            for(j=n;j>=1;j--)
            {
                dp[j] = max(dp[j],dp[j-1]+cost[i]);
                if(dp[j]-v<=EPS)
                    mm = max(dp[j],mm);
            }
        }

        cout << fixed << setprecision(2) << mm << endl;
        cin >> v >> n;
    }

    return 0;
}
