#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,m;
    cin >>n >>m;
    vector<string> c(n);
    rep(i,n) cin >>c[i];

    int ans=0;
    int size=min(n,m);
    vector<int> DX{-1,1}, DY{-1,1};

    rep(i,n)rep(j,m)for(auto &dx:DX)for(auto &dy:DY)rep(k,size)
    {
        bool valid=true;
        int t=0;
        rep(x,k+1)
        {
            int nx=j+x*dx;
            rep(y,x+1)
            {
                int ny=i+y*dy;
                if(0<=nx && nx<m && 0<=ny && ny<n)
                {
                    if(c[ny][nx]=='X')
                    {
                        valid=false;
                        break;
                    }
                    else t+=c[ny][nx]-'0';
                }
                else
                {
                    valid=false;
                    break;
                }
            }
        }
        if(valid) ans=max(ans,t);
    }

    cout << ans << endl;
    return 0;
}
