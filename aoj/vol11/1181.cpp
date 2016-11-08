#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct Dice
{
    // top,under,right,left,forward,backward
    int t,u,r,l,f,b;
    Dice(){}
    Dice(int top, int forward)
    {
        t=top;
        f=forward;
        r=detR(top,forward);
        u=7-t;
        b=7-f;
        l=7-r;
    }
    
    int detR(int T, int F)
    {
        int r=0;
        if(T==1)
        {
            if(F==2) r=3;
            else if(F==3) r=5;
            else if(F==4) r=2;
            else if(F==5) r=4;
        }
        else if(T==2)
        {
            if(F==1) r=4;
            else if(F==3) r=1;
            else if(F==4) r=6;
            else if(F==6) r=3;        
        }
        else if(T==3)
        {
            if(F==1) r=2;
            else if(F==2) r=6;
            else if(F==5) r=1;
            else if(F==6) r=5;
        }
        else if(T==4)
        {
            if(F==1) r=5;
            else if(F==2) r=1;
            else if(F==5) r=6;
            else if(F==6) r=2;
        }
        else if(T==5)
        {
            if(F==1) r=3;
            else if(F==3) r=6;
            else if(F==4) r=1;
            else if(F==6) r=4;
        }
        else if(T==6)
        {
            if(F==2) r=4;
            else if(F==3) r=2;
            else if(F==4) r=5;
            else if(F==5) r=3;        
        }
        return r;
    }
    
    vector<int> getDIR()
    {
        vector<int> ret;
        for(int i=6; i>=4; --i)
        {
            if(b==i) ret.pb(0);
            if(r==i) ret.pb(1);
            if(f==i) ret.pb(2);
            if(l==i) ret.pb(3);   
        }
        return ret;
    }
    
    Dice rotate(int dir)
    {
        if(dir==0) return Dice(f,u);
        if(dir==1) return Dice(l,f);
        if(dir==2) return Dice(b,t);
        if(dir==3) return Dice(r,f);
    }
};

int f[250][250][100];
int h[250][250];
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

int main()
{
    int n;
    while(cin >>n,n)
    {
        memset(f,0,sizeof(f));
        memset(h,0,sizeof(h));
        
        vector<Dice> d(n);
        rep(i,n)
        {
            int T,F;
            cin >>T >>F;
            d[i]=Dice(T,F);
        }
    
        rep(i,n)
        {
            int x=120,y=120;
            int height=h[y][x];
            bool move=true;
            while(1)
            {
                if(height==0 || !move)
                {
                    // printf(" %d,%d,%d : i= %d\n",y,x,height,i);
                    f[y][x][height]=i;
                    h[y][x]++;
                    break;
                }
                
                move=false;
                vector<int> dirs=d[i].getDIR();
                rep(j,dirs.size())
                {
                    int dir=dirs[j];
                    int nx=x+dx[dir], ny=y+dy[dir];
                    if(height>h[ny][nx])
                    {
                        move=true;
                        height=h[ny][nx];
                        x=nx;
                        y=ny;
                        d[i]=d[i].rotate(dir);
                        break;
                    }
                }
            }
        
        }
        
        vector<int> ans(6,0);
        rep(i,250)rep(j,250)
        {
            if(h[i][j]>0)
            {
                int idx=f[i][j][h[i][j]-1];
                ans[d[idx].t-1]++;
            }
        }
        
        rep(i,6)
        {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }        
    return 0;
}