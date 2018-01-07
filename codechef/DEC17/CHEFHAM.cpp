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

void solve()
{
    int n;
    cin >>n;

    vector<int> a(n);
    vector<pi> p(n);
    rep(i,n)
    {
        cin >>a[i];
        p[i]={a[i],i};
    }

    sort(all(p));

    int d = -1;
    vector<int> ans(n);
    if(n>4)
    {
        d=n;
        rep(i,n)
        {
            int idx = p[i].se;
            ans[idx] = p[(i+2)%n].fi;
        }
    }
    else
    {
        do {
            vector<int> v(n);
            rep(i,n) v[i]=p[i].fi;

            int t = 0;
            rep(i,n) t += (a[i]!=v[i]);
            if(d<t)
            {
                d=t;
                ans = v;
            }
        } while(next_permutation(all(p)));
    }

    printf("%d\n", d);
    rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
}

int main()
{
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
