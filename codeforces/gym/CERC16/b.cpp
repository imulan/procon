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

int main(){
    int n,m;
    cin >>n >>m;

    vector<string> s(n);
    rep(i,n) cin >>s[i];

    vector<ll> a(n),b(m);
    rep(i,n) cin >>a[i];
    rep(i,m) cin >>b[i];

    ll th;
    cin >>th;

    auto make_valid = [&](const vector<int> &mask){
        int sz = mask.size();

        vector<int> ret(1<<sz);
        rep(i,1<<sz){
            int na = 0;
            rep(j,sz)if(i>>j&1) na |= mask[j];
            ret[i] = (__builtin_popcount(i) <= __builtin_popcount(na));
        }

        rep(i,sz){
            rep(mm,1<<sz){
                if(mm>>i&1) ret[mm] &= ret[mm^(1<<i)];
            }
        }

        return ret;
    };

    vector<int> mask(n);
    rep(i,n){
        rep(j,m)if(s[i][j]=='1') mask[i] |= (1<<j);
    }

    vector<int> va = make_valid(mask);

    mask = vector<int>(m);
    rep(i,m){
        rep(j,n)if(s[j][i]=='1') mask[i] |= (1<<j);
    }

    vector<int> vb = make_valid(mask);

    vector<ll> sa,sb;
    rep(i,1<<n)if(va[i]){
        ll t = 0;
        rep(j,n)if(i>>j&1) t += a[j];
        sa.pb(t);
    }
    rep(i,1<<m)if(vb[i]){
        ll t = 0;
        rep(j,m)if(i>>j&1) t += b[j];
        sb.pb(t);
    }

    sort(all(sa));
    sort(all(sb));
    int A = sa.size(), B = sb.size();

    int bidx = B-1;
    ll ans = 0;
    rep(aidx,A){
        while(bidx>=0 && sa[aidx] + sb[bidx] >= th) --bidx;
        ans += B-1-bidx;
    }
    cout << ans << endl;

    return 0;
}
