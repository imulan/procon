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

int main()
{
    int M,F;
    cin >>M >>F;

    vector<pi> m(M),f(F);
    rep(i,M) cin >>m[i].se >>m[i].fi;
    rep(i,F) cin >>f[i].fi >>f[i].se;

    sort(all(m));
    sort(all(f));

    int ans = 0;
    multiset<int> s;
    int idx = 0;
    rep(i,F)
    {
        while(idx<M && m[idx].fi<=f[i].fi) s.insert(m[idx++].se);

        if(!s.empty())
        {
            auto itr = s.lower_bound(f[i].se);
            if(itr != s.end())
            {
                ++ans;
                s.erase(itr);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
