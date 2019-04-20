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

struct RollingHash{
    static const int MD = 2;
    static const vector<ll> hash_base, hash_mod;

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        rep(i,MD){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            rep(j,n){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    // 1-index
    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        rep(i,MD) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }

    ll calc(int l, int r){
        ll ret = 0;
        rep(i,MD) ret |= (hash_value(l-1,r,i)<<(i*31));
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{1009,1021,1013};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007,1000000021};

const int A = 26;

void solve(){
    string w,s;
    cin >>w >>s;
    int W = w.size(), S = s.size();

    vector<int> ctw(A);
    rep(i,W) ++ctw[w[i]-'a'];

    RollingHash h(s);

    map<ll,int> hash2start;
    vector<ll> val(S);
    rep(i,S-W+1){
        val[i] = h.calc(i+1, i+W);
        hash2start[val[i]] = i;
    }

    map<ll,int> freq;

    vector<int> cts(A);
    rep(i,W-1) ++cts[s[i]-'a'];
    for(int i=W-1; i<S; ++i){
        ++cts[s[i]-'a'];
        if(cts == ctw) ++freq[val[i-(W-1)]];
        --cts[s[i-(W-1)]-'a'];
    }

    if(freq.empty()){
        cout << -1 << endl;
        return;
    }

    int m = 0;
    for(const auto &p:freq) m = max(m,p.se);
    // dbg(m);

    string ans(W,'z');
    for(const auto &p:freq){
        if(p.se == m){
            ll v = p.fi;
            int st = hash2start[v];
            string t = s.substr(st,W);
            ans = min(ans,t);
        }
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
