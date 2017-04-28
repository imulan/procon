#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using P = pair<int,string>;

struct RollingHash{
    static const int MD = 3;
    const vector<ll> hash_base{1009,1021,1013};
    const vector<ll> hash_mod{1000000009,1000000007,1000000021};

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        for(int i=0; i<MD; ++i){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for(int j=0; j<n; ++j){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    // 1-index
    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        for(int i=0; i<MD; ++i) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }

    vector<ll> calc(int l, int r){
        vector<ll> ret(3);
        rep(i,3) ret[i]=hash_value(l-1,r,i);
        return ret;
    }
};

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
    for(int L=N; L>0; --L)if(s[L].size())
    {
        // 長さが同じもの
        map<vector<ll>,int> same;
        rep(i,s[L].size())
        {
            string t=s[L][i];
            reverse(all(t));

            RollingHash th(t);
            ++same[th.calc(1,L)];
        }
        rep(i,s[L].size())
        {
            string t=s[L][i];
            reverse(all(t));

            RollingHash hh(s[L][i]);
            ans += same[hh.calc(1,L)]-(s[L][i]==t);
        }

        // 長さが違うもの
        rep(i,s[L].size())
        {
            string t=s[L][i];
            reverse(all(t));

            RollingHash th(t);
            ans += ct[th.calc(1,L)];
        }

        // ハッシュのカウントを更新
        rep(i,s[L].size())
        {
            string t=s[L][i];
            reverse(all(t));

            RollingHash hh(s[L][i]),th(t);
            for(int pl=1; pl<L; ++pl)
            {
                // s[L][i]の先頭からpl文字が回文になっているか？
                if(hh.calc(1,pl) == th.calc(L-pl+1,L)) ++ct[hh.calc(pl+1,L)];
                // s[L][i]の末尾からpl文字が回文になっているか？
                if(hh.calc(L-pl+1,L) == th.calc(1,pl)) ++ct[hh.calc(1,L-pl)];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
