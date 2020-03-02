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

int solve(){
    int n;
    cin >>n;

    map<ll,int> v2id;
    vector<ll> b(n);
    rep(i,n){
        cin >>b[i];
        v2id[b[i]] = i;
    }
    sort(all(b));

    if(n<=3) return 1;

    map<ll,int> w2id;
    rep(i,n-1){
        ll w = b[i+1]-b[i];
        w2id[w] = i;
    }
    if(w2id.size() >= 4) return -1;

    set<int> cand;
    for(const auto &p:w2id){
        rep(i,2) cand.insert(p.se+i);
    }

    for(int bidx:cand){
        vector<ll> x;
        rep(i,n)if(i!=bidx) x.pb(b[i]);

        int X = n-1;
        ll w = x[1]-x[0];

        bool ok = true;
        rep(i,X-1)if(x[i+1]-x[i] != w) ok = false;
        if(ok){
            int ans = v2id[b[bidx]];
            return ans+1;
        }
    }
    return -1;
}

int main(){
    cout << solve() << "\n";
    return 0;
}
