#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int cnt[4];
    
    cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    
    

    int total = cnt[0] + cnt[1] + cnt[2] + cnt[3];

    // 循环，num个数是否为0
    for(int num = 0; num < 4; num++)if(cnt[num])
    {
        // 答案和临时数组初始化
        vector<int> res;
        int tmp[4];
        for(int i = 0; i < 4; i++) 
            tmp[i] = cnt[i];

        // num入栈
        int last = num;
        res.push_back(num);
        tmp[num]--;

        // 暴力构造，有比num小的，就先压入，没有就压大的
        // 都不满足退出循环，num+1做下一次尝试
        for(int i = 0; i < total-1; i++)
        {
            if(tmp[last-1] && last > 0)
            {
                res.push_back(last-1);
                tmp[last-1]--;
                last--;
            }
            else if(tmp[last+1] && last < 3)
            {
                res.push_back(last+1);
                tmp[last+1]--;
                last++;
            }
            else
                break;
        }

        if((int)res.size() == total)
        {
            cout << "YES" << endl;
            for(int i = 0; i < (int)res.size(); i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;
            return 0;
        }
    } 
    cout << "NO" << endl;
    return 0;
}
