#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const ll INF = 1010101010;
using pl = pair<ll,ll>;

pl f(ll x, ll rem){
    ll mn = (rem*(2*x+rem-1))/2;
    if(mn>INF) mn=INF;

    ll pw = 1;
    rep(i,rem){
        pw *= 2;
        if(pw > INF) break;
    }

    ll mx = (pw-1)*x;
    if(mx>INF) mx=INF;

    return {mn,mx};
}

int main(){
    int n,k;
    cin >>n >>k;

    ll s = -1;
    ll l=0, r=n+1;
    while(r-l>1){
        ll x = (l+r)/2;
        pl p = f(x,k);

        if(p.fi<=n && n<=p.se){
            s = x;
            break;
        }

        if(n < p.fi) r = x;
        else if(p.se < n) l = x;
        else assert(false);
    }

    if(s == -1){
        cout << "NO" << "\n";
        return 0;
    }

    vector<int> ans;
    ans.pb(s);
    --k;
    n -= s;

    while(k){
        // dbg(s); dbg(k); dbg(n); dbg(ans);
        l = s;
        r = 2*s+1;
        bool upd = false;
        while(r-l>1){
            ll x = (l+r)/2;
            pl p = f(x,k);

            if(p.fi<=n && n<=p.se){
                upd = true;
                s = x;
                ans.pb(x);
                n -= x;
                break;
            }

            if(n < p.fi) r = x;
            else if(p.se < n) l = x;
            else assert(false);
        }
        assert(upd);
        --k;
    }

    cout << "YES" << "\n";
    int A = ans.size();
    rep(i,A) cout << ans[i] << " \n"[i==A-1];
    return 0;
}
