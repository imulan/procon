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
        return (hash_value(l-1,r,0)<<32) | hash_value(l-1,r,1);
    }
};
const vector<ll> RollingHash::hash_base{1009,1021};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007};

const int N = 3000000;

int calc(const string &s, const string &t, int ok){
    int S = s.size(), T = t.size();

    RollingHash hs(s);

    int ng = S/T+1;
    if(ok>0){
        if(ng == ok+1) return ok;
        ng = ok+2;
    }
    // dbg(ng);
    while(ng-ok>1){
        int mid = (ok+ng)/2;

        string tt = "";
        string nt = t;
        rep(i,30){
            if(mid>>i&1) tt += nt;

            nt += nt;
            if(nt.size() > N) break;
        }
        RollingHash ht(tt);

        int TT = T*mid;
        ll tv = ht.calc(1, TT);

        bool valid = false;
        for(int i=1; i+TT-1<=S; ++i){
            if(hs.calc(i,i+TT-1) == tv){
                valid = true;
                break;
            }
        }

        if(valid) ok = mid;
        else ng = mid;
    }
    // dbg(s);dbg(ok);
    return ok;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    string s,t;
    cin >>s >>t;

    int T = t.size();
    string p = s;
    while(p.size() < 3*T) p += s;
    if(p == s) p += s;
    int x = calc(p,t,0);

    p += p;
    int y = calc(p,t,x);

    int ans = x;
    if(x!=y) ans = -1;
    cout << ans << endl;
    return 0;
}
