// http://acm.hdu.edu.cn/showproblem.php?pid=1022
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    int n,i,j,k;
    char s1[20],s2[20];
    int res[50];
    while(~scanf("%d %s%s",&n,s1,s2)){
        stack<char> s;
        i = 0;
        j = 0;
        k = 0;
        // in:1,out:0
        //将第一辆火车压栈
        s.push(s1[0]);
        res[0] = 1;
        while(i<n){
            // 如果栈非空，且栈顶元素为要出栈的
            if(!s.empty() && s.top()==s2[j]){
                // 记录出栈动作
                res[++k] = 0;
                s.pop();
                j++;
            }
            else{
                // 否则继续压栈
                s.push(s1[++i]);
                res[++k] = 1;
            }
        }
        if(j!=n) cout << "No.\n" << "FINISH\n";
        else{
            cout << "Yes.\n";
            for(int h=0;h<k;h++){
                if(res[h]==1) cout << "in\n";
                else cout << "out\n";
            }
            cout << "FINISH\n";
        }

    }
    return 0;
}
