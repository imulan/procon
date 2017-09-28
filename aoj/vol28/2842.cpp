#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;
using P = pair<int,pi>;

struct BIT2D{
    int H,W;
    vector<vector<ll>> bit;

    BIT2D(int h, int w){
        H = h;
        W = w;
        bit = vector<vector<ll>>(h+1,vector<ll>(w+1));
    }

    void add(int y, int x, ll w){
        for(int j=y; j<=H; j+=j&-j){
            for(int i=x; i<=W; i+=i&-i){
                bit[j][i] += w;
            }
        }
    }

    ll sum(int y, int x){
        ll ret = 0;
        for(int j=y; j>0; j-=j&-j){
            for(int i=x; i>0; i-=i&-i){
                ret += bit[j][i];
            }
        }
        return ret;
    }

    ll sum(int ly, int lx, int ry, int rx){
        return sum(ry,rx) - sum(ry,lx-1) - sum(ly-1,rx) + sum(ly-1,lx-1);
    }
};

int main()
{
    int h,w,T,Q;
    scanf(" %d %d %d %d", &h, &w, &T, &Q);

    BIT2D yet(h,w),done(h,w);
    queue<P> que;
    while(Q--)
    {
        int t,c,h1,w1;
        scanf(" %d %d %d %d", &t, &c, &h1, &w1);

        while(!que.empty())
        {
            P now = que.front();
            if(now.fi+T <= t)
            {
                que.pop();
                int py = now.se.fi, px = now.se.se;
                yet.add(py,px,-1);
                done.add(py,px,1);
            }
            else break;
        }

        if(c==2)
        {
            int h2,w2;
            scanf(" %d %d", &h2, &w2);
            printf("%lld %lld\n", done.sum(h1,w1,h2,w2), yet.sum(h1,w1,h2,w2));
        }
        else
        {
            if(c==0)
            {
                if(yet.sum(h1,w1,h1,w1)+done.sum(h1,w1,h1,w1)==0)
                {
                    yet.add(h1,w1,1);
                    que.push({t,{h1,w1}});
                }
            }
            else
            {
                if(done.sum(h1,w1,h1,w1)==1) done.add(h1,w1,-1);
            }
        }
    }

    return 0;
}
