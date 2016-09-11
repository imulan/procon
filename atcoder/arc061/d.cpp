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

int main()
{
    int h,w,n;
    cin >>h >>w >>n;

    vector<pi> v(n);
    //既に見終わった
    set<pi> s;
    //黒い位置
    set<pi> black;
    rep(i,n)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        v[i]=pi(a,b);
        black.insert(v[i]);
    }

    #define IN(x,y) (1<=x && x<=w-2 && 1<=y && y<=h-2)
    ll ans[10]={0};

    rep(i,n)
    {
        for(int dy=-2; dy<=0; ++dy)for(int dx=-2; dx<=0; ++dx)
        {
            int sy=v[i].fi+dy, sx=v[i].se+dx;
            if(IN(sx,sy))
            {
                if(s.find(pi(sy,sx)) == s.end())
                {
                    s.insert(pi(sy,sx));
                    int ct=0;
                    rep(j,3)rep(k,3)
                    {
                        if(black.find(pi(sy+j,sx+k)) != black.end()) ++ct;
                    }

                    // printf("(%d,%d) = %d\n",sx,sy,ct );
                    ++ans[ct];
                }
            }
        }
    }

    ll nonzero=0;
    for(int i=1; i<=9; ++i) nonzero+=ans[i];
    ans[0]=(ll)(h-2)*(w-2)-nonzero;

    rep(i,10) cout << ans[i] << endl;
    return 0;
}
