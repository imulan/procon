#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main()
{
    int h,w,n;
    cin >>h >>w >>n;

    vector<pi> p(n);
    set<pi> x;
    rep(i,n)
    {
        int r,c;
        cin >>r >>c;
        p[i]=pi(r,c);
        x.insert(p[i]);
    }

    ll ans = (ll)(h-1)*w + (ll)h*(w-1);

    ll double_count=0;

    #define IN(x,y) (1<=x && x<=w && 1<=y && y<=h)
    rep(i,n)
    {
        rep(j,4)
        {
            int ny=p[i].fi+dy[j], nx=p[i].se+dx[j];
            if(IN(nx,ny))
            {
                --ans;
                if(x.find(pi(ny,nx))!=x.end()) ++double_count;
            }
        }
    }

    cout << ans+double_count/2 << endl;
    return 0;
}
