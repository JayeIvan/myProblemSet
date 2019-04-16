// http://acm.hdu.edu.cn/showproblem.php?pid=1020
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N,num,i,j;
    string str,res,numtmp;
    char temp;
    cin >> N;
    while(N--){
        cin >> str;
        res = "";
        for(i=0;i<str.size();){
            temp = str[i];
            num = 1;
            for(j=i+1;str[i]==str[j];j++){
                num++;
            }
            if(num!=1) cout << num;
            cout << str[i];

//            if(num!=1){
//                numtmp = "";
//                while(num){
//                    numtmp += (num%10 + '0');
//                    num /= 10;
//                }
//            }
//            for(int k=numtmp.size()-1;k>=0;k--)res += numtmp[k];
//            res += str[i];
            i = j;
        }
        cout << endl;
    }
    return 0;
}
