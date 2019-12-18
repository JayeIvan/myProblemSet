#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;

int res[205];

int main()
{
    string str;
    int n;

    while(cin >> n)
    {
        cin >> str;
        string tmp = str;
        memset(res, 0, sizeof(res));
        int t = 0;

        for(int i = 0; i < n-1; i++)
        {
            if(str[i]=='B')
            {
                str[i] = 'W';
                if(str[i+1]=='B') str[i+1] = 'W';
                else str[i+1] = 'B';
                res[t++] = i+1;
            }
            
        }

        if(str[n-1]=='W')
        {
            if(t>0)
            {
                cout << t << endl;
                for(int i = 0; i < t; i++) printf("%d ", res[i]);
                printf("\n");
            }
            else cout << "0" << endl;
        }
        else
        {
            t = 0;
            str = tmp;
            memset(res, 0, sizeof(res));
            for(int i = 0; i < n-1; i++)
            {
                if(str[i]=='W')
                {
                    str[i] = 'B';
                    if(str[i+1]=='B') str[i+1] = 'W';
                    else str[i+1] = 'B';
                    res[t++] = i+1;
                }
            }
            if(str[n-1]=='W') cout << "-1\n";
            else
            {
                if(t>0)
                {
                    cout << t << endl;
                    for(int i = 0; i < t; i++) printf("%d ", res[i]);
                    printf("\n");
                }
                else cout << "0" << endl;
            }
        }
        
    }

    return 0;
}
