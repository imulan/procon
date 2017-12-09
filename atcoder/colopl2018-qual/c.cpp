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

bool valid[1<<18];

ll G[35][35];
ll go[35][35];

int main()
{
    ll a,b;
    cin >>a >>b;

    vector<ll> e,o;
    for(ll i=a; i<=b; ++i)
    {
        if(i%2==0) e.pb(i);
        else o.pb(i);
    }

    int E = e.size();
    int O = o.size();
    rep(i,E)rep(j,O) G[i][j]=__gcd(e[i],o[j]);

    rep(i,O)rep(j,O) go[i][j]=__gcd(o[i],o[j]);


    valid[0]=true;
    rep(mask,1<<O)if(valid[mask])
    {
        rep(i,O)if(!(mask>>i&1))
        {
            int nmask = mask|(1<<i);

            bool v = true;
            rep(j,O)if(mask>>j&1)
            {
                if(go[i][j]!=1) v = false;
            }

            if(!valid[nmask]) valid[nmask] = v;
        }
    }


    ll ans = 0;
    rep(mask,1<<O)if(valid[mask])
    {
        ++ans;

        rep(i,e.size())
        {
            int add = 1;
            rep(j,O)if(mask>>j&1)
            {
                if(G[i][j]!=1)
                {
                    add=0;
                    break;
                }
            }
            ans += add;
        }
    }

    cout << ans << endl;
    return 0;
}
