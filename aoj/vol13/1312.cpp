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

using vl = vector<ll>;

const vl base{1009,1021};
const ll MOD = 1000000009;
// const vl mod{1000000009,1000000007};

// 2次元ハッシュ
// sの各P*Q部分のハッシュを計算
vector<vl> calc_hash(const vector<string> &s, int P, int Q){
    int n = s.size(), m = s[0].size();

    vector<vector<ll>> tmp(n,vl(m)), hash(n,vl(m));

    ll t0 = 1;
    rep(j,Q) (t0 *= base[0]) %= MOD;

    // 行方向
    rep(i,n){
        ll e = 0;
        rep(j,Q) e = (e*base[0] + s[i][j]) % MOD;

        for(int j=0; j+Q<=m; ++j){
            tmp[i][j] = e;
            if(j+Q < m) e = (e*base[0] - (t0*s[i][j])%MOD + MOD + s[i][j+Q]) % MOD;
        }
    }

    ll t1 = 1;
    rep(i,P) (t1 *= base[1]) %= MOD;

    for(int j=0; j+Q<=m; ++j){
        ll e = 0;
        rep(i,P) e = (e*base[1] + tmp[i][j]) % MOD;

        for(int i=0; i+P<=n; ++i){
            hash[i][j] = e;
            if(i+P < n) e = (e*base[1] - (t1*tmp[i][j])%MOD + MOD + tmp[i+P][j]) % MOD;
        }
    }

    return hash;
}

string f(char c){
    int a;
    if('A'<=c && c<='Z') a = c-'A';
    else if('a'<=c && c<='z') a = c-'a'+26;
    else if('0'<=c && c<='9') a = c-'0'+52;
    else if(c=='+') a=62;
    else a=63;

    string r = "";
    rep(i,6){
        if(a%2==1) r = "1"+r;
        else r = "0"+r;
        a/=2;
    }
    return r;
}

string decode(const string &s, int L){
    string t = "";
    rep(i,s.size()) t += f(s[i]);
    t.resize(L);
    return t;
}

int main(){
    int w,h,p;
    while(cin >>w >>h >>p,w){
        vector<string> img,pat;

        rep(i,h){
            string s;
            cin >>s;
            img.pb(decode(s,w));
        }

        rep(i,p){
            string s;
            cin >>s;
            pat.pb(decode(s,p));
        }

        // rep(i,h) cout << img[i] << endl;
        // rep(i,p) cout << pat[i] << endl;

        auto rotate = [&](const vector<string> &s){
            vector<string> ret(s);
            rep(i,p)rep(j,p) ret[p-1-j][i] = s[i][j];
            return ret;
        };

        vector<vl> hs_i = calc_hash(img,p,p);
        set<ll> hs_pat;
        rep(_,2){
            vector<string> t(pat);
            rep(i,p)rep(j,p) pat[i][p-j-1] = t[i][j];

            rep(i,4){
                vector<vl> vv = calc_hash(pat,p,p);
                hs_pat.insert(vv[0][0]);
                pat = rotate(pat);
            }
        }

        int ans = 0;
        rep(i,h-p+1)rep(j,w-p+1){
            if(hs_pat.count(hs_i[i][j])) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
