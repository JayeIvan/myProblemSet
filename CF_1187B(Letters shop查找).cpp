#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

// ��һ����λ���飬��ÿ����ĸand��Ӧ�����Ķ�Ӧλ�ü�¼��������map���ǲ���̫��ʱ�ˣ�test4��TLE��
vector<int> letter[26];

int main()
{
    int n,m,cnt[26],res;
    string s,t;
    scanf("%d",&n);
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        letter[s[i]-'a'].push_back(i);
    }

    scanf("%d",&m);
    while(m--)
    {
        memset(cnt,0,sizeof(cnt));
        res = 0;
        cin >> t;
        for(int i=0;i<t.size();i++)
        {
            int c = t[i]-'a';
            cnt[c] += 1;
            res = max(res,letter[c][cnt[c]-1]+1);
        }
        printf("%d\n",res);
    }
    return 0;
}


// TLE map���һ��Ƿ�ʱ��hhh��¼һ��map��value����@_@

//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <string>
//#include <cstdio>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//typedef struct{
//    char c;
//    int num;
//}letter;
//char s[200005],cnt[26];
//map<int,letter> str;
//
//bool operator==(const letter &a,const letter &b)
//{
//    return a.c==b.c && a.num== b.num;
//}
//
//class map_value_finder
//{
//public:
//       map_value_finder(const letter &l):ll(l){}
//       bool operator ()(const map<int, letter>::value_type &pair)
//       {
//            return pair.second == ll;
//       }
//private:
//        const letter ll;
//};
//
//int main()
//{
//    int n,m,c,num,index,res;
//    letter l;
//    scanf("%d",&n);
//    scanf("%s",s);
//    memset(cnt,0,sizeof(cnt));
//    for(int i=0;i<n;i++)
//    {
//        l.c = s[i];
//        cnt[l.c-'a'] += 1;
//        l.num = cnt[l.c-'a'];
//        str.insert(pair<int,letter>(i+1,l));
//    }
//
//    map<int, letter>::iterator iter;
//
//    scanf("%d",&m);
//    for(int i=0;i<m;i++)
//    {
//        scanf("%s",s);
//        res = 0;
//        memset(cnt,0,sizeof(cnt));
//        for(int i=0;i<strlen(s);i++)
//        {
//            cnt[s[i]-'a'] += 1;
//        }
//
//        for(int i=0;i<26;i++)
//        {
//            l.c = 'a'+i;
//            l.num = cnt[i];
//            //cout << l.c << " " << l.num << endl;
//            if(l.num>0)
//            {
//                iter = find_if(str.begin(),str.end(),map_value_finder(l));
//                //cout << "iter_fst:" << iter->first << endl;
//                res = max(res,iter->first);
//            }
//            if(res==n) break;
//        }
//        printf("%d\n",res);
//    }
//
//    return 0;
//}
