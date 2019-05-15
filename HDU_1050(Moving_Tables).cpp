#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
找重合次数最多的走廊
一旦要移动桌子的时候，走廊被重合，不能同时移动，就要多用一个10min
*/

int main()
{
    int t,n,i,j,cnt[205],first,second,mm;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(cnt,0,sizeof(int)*205);

        for(i=1;i<=n;i++)
        {
            cin >> first >> second;
            if(first>second)
            {
                int temp = first;
                first = second;
                second = temp;
            }

            first = (first+1)/2;
            second = (second+1)/2;

            for(j=first;j<=second;j++)
            {
                cnt[j]++;
            }
        }

        sort(cnt,cnt+200,greater<int>());
        cout << cnt[0]*10 << endl;
    }
    return 0;
}





/*
以下是脑残的WAWAWAWAWAWAWAWA

把整个数组按照开始的房间进行排序然后看，
下一个元素开始的房间是否比前一个结束的
房间小如果小的话，肯定就是要+1
*/

//class Arr{
//public:
//    int first,second;
//    bool operator< (const Arr& rt){
//      return this->first < rt.first;
//    }
//};
//
//
//int main(){
//    Arr arrs[201];
//    int t,n,i,j,current,cnt,vis[201];
//    cin >> t;
//    while(t--){
//        cnt = 0;
//        cin >> n;
//        memset(arrs,0,sizeof(Arr)*201);
//        memset(vis,0,sizeof(int)*201);
//
//        // 输入
//        for(i=1;i<=n;i++){
//            cin >> arrs[i].first >> arrs[i].second;
//            if(arrs[i].first > arrs[i].second){
//                int t = arrs[i].first;
//                arrs[i].first = arrs[i].second;
//                arrs[i].second = t;
//            }
//        }
//
//        // 排序
//        sort(arrs,arrs+n);
//
//        // 遍历划分，已划分过的vis改为1
//        for(i=1;i<=n;i++){
//
//            // 如果未访问过
//            if(!vis[i]){
//                current = (arrs[i].second+1)/2;
//                vis[i] = 1;
//                cnt += 10;
//
//                for(j = i+1;j<=n && !vis[j];j++){
//                    int temp = (arrs[j].first+1)/2;
//                    if(temp > current){
//                        current = (arrs[j].second+1)/2;
//                        vis[j] = 1;
//                    }
//                }
//            }
//        }
//        cout << cnt << endl;
//    }
//    return 0;
//}
