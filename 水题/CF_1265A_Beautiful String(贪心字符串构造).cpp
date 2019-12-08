#include<iostream>
#include<string>
 
using namespace std;
 
int main()
{
    int n;
    string str;
    cin >> n;
    bool flag;
    while (n--)
    {
        cin >> str;
        flag = true;
        for (int i = 0; i < str.length() && flag ; i++)
        {
            if(str[i]!='?' && str[i+1]!='?' && str[i]==str[i+1]) flag = false;
        }
 
        if(flag)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if(str[i]=='?'){
                    if(str[i-1]!='a' && str[i+1]!='a') str[i] = 'a';
                    else if(str[i-1]!='b' && str[i+1]!='b') str[i] = 'b';
                    else if(str[i-1]!='c' && str[i+1]!='c') str[i] = 'c';
                }
            }
            
            cout << str << endl;
        }
        else cout << -1 << endl;
 
    }
    
    return 0;
}