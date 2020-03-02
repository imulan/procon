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

using P = pair<ll,int>;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    int n,q;
    string s;
    cin >>n >>s >>q;

    vector<P> x(q);
    rep(i,q){
        cin >>x[i].fi;
        x[i].se = i;
    }
    sort(all(x));

    vector<char> ans(q);
    int qidx = 0;
    ll sum = 0;
    for(int i=1; i<=n; ++i){
        ll ns = sum+i;
        while(qidx<q && x[qidx].fi<=ns){
            ll idx = x[qidx].fi-sum-1;
            ans[x[qidx].se] = s[idx];
            ++qidx;
        }

        sum = ns;
    }

    rep(i,q) cout << ans[i] << "\n";
    return 0;
}
