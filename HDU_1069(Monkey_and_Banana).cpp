// http://acm.hdu.edu.cn/showproblem.php?pid=1069
#include <iostream>
#include <algorithm>

using namespace std;

class Block
{
public:
    int l,w,h;
    Block(){}
    Block(int xx,int yy,int zz):l(xx),w(yy),h(zz){}
    void Sort()
    {
        int t;
        if(l<w)
        {
            t = l;
            l = w;
            w = t;
        }
        if(l<h)
        {
            t = l;
            l = h;
            h = t;
        }
        if(w<h)
        {
            t = w;
            w = h;
            h = t;
        }
    }
};

bool cmp(Block b1,Block b2)
{
    return b1.l > b2.l;
}

int main()
{
    int n,i,j,x,y,z,height,cnt = 0;
    cin >> n;
    while(n!=0)
    {
        Block block[185];
        for(i=0;i<3*n;i+=3)
        {
            cin >> x >> y >> z;
            block[i] = Block(x,y,z);
            block[i].Sort();
            block[i+1].l = block[i].l;
            block[i+1].w = block[i].h;
            block[i+1].h = block[i].w;

            block[i+2].l = block[i].w;
            block[i+2].w = block[i].h;
            block[i+2].h = block[i].l;
        }

        sort(block,block+3*n,cmp);

        int heig[185],ans=0;
        heig[0] = block[0].h;
        for(i=1;i<3*n;i++)
        {
            height = 0;
            for(j=0;j<i;j++)
            {
                if(block[j].l>block[i].l && block[j].w>block[i].w)
                {
                    height = max(heig[j],height);
                }
            }
            heig[i] = height+block[i].h;
            ans = max(heig[i],ans);
        }
        cout << "Case " << ++cnt << ": maximum height = " << ans << endl;
        cin >> n;
    }
    return 0;
}
