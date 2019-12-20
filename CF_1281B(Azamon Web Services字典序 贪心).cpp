#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

// 倒序搜索字符
int searchIndex(string str, char a)
{
    for(int i = str.length()-1; i >= 0; i--)
        if(str[i] == a) 
            return i;
    return 0;
}

int main()
{
    int n;
    string a,b,tmp;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        tmp = a;
        // 将字符串排序
        for(int i = 0; i < tmp.length(); i++)
            for(int j = i; j < tmp.length(); j++)
                if(tmp[i] > tmp[j]) 
                    swap(tmp[i], tmp[j]);
        
        // 找到第一个与原字符串不匹配的字符的位置
        // 在原字符串中倒序查找他的位置，在原字符串中交换
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != tmp[i])
            {
                int x = searchIndex(a,tmp[i]);
                swap(a[i], a[x]);
                break;
            }
        }

        // string直接比较
        if(a < b) cout << a << endl;
        else cout << "---" << endl;
    }
    return 0;
}
