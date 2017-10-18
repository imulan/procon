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

const int N = 100001;
vector<int> X[N];

const int S = 70;

inline ll C2(ll n)
{
    return n*(n-1)/2;
}

int main()
{
    int n;
    cin >>n;
    vector<pi> p(n);
    rep(i,n) cin >>p[i].fi >>p[i].se;

    sort(all(p));

    rep(i,n) X[p[i].fi].pb(p[i].se);

    vector<int> can;
    rep(i,N)if(X[i].size()>=2) can.pb(i);

    ll ans = 0;

    map<pi,ll> ct;
    for(int x=1; x<N; ++x)
    {
        int SZ = X[x].size();
        if(SZ>S)
        {
            rep(i,can.size())if(x!=can[i])
            {
                int CAN_SZ = X[can[i]].size();
                if(CAN_SZ>S && can[i]>x) continue;

                int ii=0, xx=0;
                int cnt_y = 0;
                while(ii<CAN_SZ && xx<SZ)
                {
                    if(X[can[i]][ii] == X[x][xx])
                    {
                        ++cnt_y;
                        ++ii;
                        ++xx;
                    }
                    else if(X[can[i]][ii]>X[x][xx]) ++xx;
                    else ++ii;
                }

                ans += C2(cnt_y);
            }
        }
        else
        {
            rep(i,SZ)rep(j,i) ++ct[{X[x][j],X[x][i]}];
        }
    }

    for(const auto &t:ct) ans += C2(t.se);

    cout << ans << endl;
    return 0;
}
