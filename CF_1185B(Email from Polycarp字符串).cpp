#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n,i,j,poss,post;
    string s,t;
    while(cin >> n)
    {
        while(n--)
        {
            cin >> s >> t;
            if(s.size()>t.size() || s[0]!=t[0] || s[s.size()-1]!=t[t.size()-1])
            {
                printf("NO\n");
            }
            else
            {
                bool flag = true;
                for(poss=0,post=0,j=0;j<s.size() && flag;)
                {
                    i=post+1;
                    j=poss+1;
                    if(t[post]!=s[poss])
                    {
                        flag = false;
                        break;
                    }
                    char c = s[poss];
                    while(c==t[i] && i<=t.size()) i++;
                    while(c==s[j] && j<=s.size()) j++;

                    if(i-post<j-poss)
                    {
                        //cout << "false\n";
                        flag = false;
                        break;
                    }

                    poss = j;
                    post = i;

                }

                if(flag && t.size()==i) printf("YES\n");
                else printf("NO\n");
            }
        }
    }

    return 0;
}

/*
10
aaaa
aaaab
aaaa
baaaa
hello
hellooooao
a
b
aaaaa
aaaa
abcdefghijklmnopqrstuvwxyz
zabcdefghijklmnopqrstuvwxyz
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaba
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
abaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
zz
z
aaaabbbbaaaa
aaaaabbbaaaa
*/

