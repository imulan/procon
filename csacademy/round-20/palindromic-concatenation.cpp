#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct RollingHash{
    static const int MD = 3;
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

    vector<ll> calc(int l, int r){
        vector<ll> ret(MD);
        rep(i,MD) ret[i]=hash_value(l-1,r,i);
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{1009,1021,1013};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007,1000000021};

const int N=100000;
vector<string> s[N+1];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;

    rep(i,n)
    {
        string tmp;
        cin >>tmp;
        s[tmp.size()].pb(tmp);
    }

    map<vector<ll>,ll> ct;
    ll ans = 0;

    for(int L=N; L>0; --L)
    {
        int SZ=s[L].size();
        if(!SZ) continue;

        vector<string> t(SZ);
        vector<RollingHash> hh(SZ),th(SZ);
        rep(i,SZ)
        {
            t[i]=s[L][i];
            reverse(all(t[i]));

            hh[i] = RollingHash(s[L][i]);
            th[i] = RollingHash(t[i]);
        }

        // 長さが同じもの
        map<vector<ll>,int> same;
        rep(i,SZ) ++same[th[i].calc(1,L)];
        rep(i,SZ) ans += same[hh[i].calc(1,L)]-(s[L][i]==t[i]);

        // 長さが違うもの
        rep(i,SZ) ans += ct[th[i].calc(1,L)];

        // ハッシュのカウントを更新
        rep(i,SZ)for(int pl=1; pl<L; ++pl)
        {
            // s[L][i]の先頭からpl文字が回文になっているか？
            if(hh[i].calc(1,pl) == th[i].calc(L-pl+1,L)) ++ct[hh[i].calc(pl+1,L)];
            // s[L][i]の末尾からpl文字が回文になっているか？
            if(hh[i].calc(L-pl+1,L) == th[i].calc(1,pl)) ++ct[hh[i].calc(1,L-pl)];
        }
    }

    cout << ans << endl;
    return 0;
}
