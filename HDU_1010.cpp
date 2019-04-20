// http://acm.hdu.edu.cn/showproblem.php?pid=1010

#include <cstdio>
#include <iostream>
using namespace std;

int mat[7][7],vis[7][7];
int st1,st2,d1,d2;
int m,n,t;
bool flag;

int abs(int a,int b)
{
    if(a<b) return b-a;
    else return a-b;
}

void dfs(int step,int s1,int s2){
    // 数组越界
    if(s1>=m || s2>=n || s1<0 || s2<0) return;

    // 时间用完，走到的点刚好是door，输出YES，flag为false表示已经找到解
    if(step==0 && flag){
        if(s1==d1 && s2==d2){
            cout << "YES\n";
            flag = false;
        }
    }
    else if(flag){
        // 往右移动一步
        if(mat[s1][s2+1]==1 && vis[s1][s2+1]==0){
            vis[s1][s2+1] = 1;
            dfs(step-1,s1,s2+1);
            vis[s1][s2+1] = 0;
        }
        // 往下移动一步
        if(mat[s1+1][s2]==1 && vis[s1+1][s2]==0){
            vis[s1+1][s2] = 1;
            dfs(step-1,s1+1,s2);
            vis[s1+1][s2] = 0;
        }
        // 往左移动一步
        if(mat[s1][s2-1]==1 && vis[s1][s2-1]==0){
            vis[s1][s2-1] = 1;
            dfs(step-1,s1,s2-1);
            vis[s1][s2-1] = 0;
        }
        // 往上移动一步
        if(mat[s1-1][s2]==1 && vis[s1-1][s2]==0){
            vis[s1-1][s2] = 1;
            dfs(step-1,s1-1,s2);
            vis[s1-1][s2] = 0;
        }
    }
}

int main(){
    char temp;
    cin >> m >> n >> t;
    while(m || n || t){
        flag = true;
        // 初始化vis和mat
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                vis[i][j] = 0;
                mat[i][j] = 0;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> temp;
                switch(temp){
                    case '.':
                        mat[i][j] = 1;
                        break;
                    case 'X':
                        mat[i][j] = 10000;
                        break;
                    case 'S':
                        mat[i][j] = 1;
                        vis[i][j] = 1;
                        st1 = i;
                        st2 = j;
                        break;
                    case 'D':
                        mat[i][j] = 1;
                        d1 = i;
                        d2 = j;
                        break;
                }
            }
        }
        // 最短路径
        int tmp = abs(st1,d1)+abs(st2,d2);
        // 奇偶剪枝
        if(t<tmp || (t-tmp)%2==1){
            flag = false;
            cout << "NO\n";
        }
        else dfs(t,st1,st2);
        if(flag) cout << "NO\n";
        cin >> m >> n >> t;
    }
    return 0;
}

/*
test
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D
5 5 18
S..X.
..X..
X..x.
..X.D
.....
0 0 0
*/
