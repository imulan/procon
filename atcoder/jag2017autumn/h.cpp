#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back((x))
#define fi first
#define se second

using ll = long long;
using vl = vector<ll>;

const ll hash_base[2] = {1009,1021};
const ll hash_mod[2] = {1000000009,1000000007};

const int MD = 2;
const int N = 100010;

ll hs[MD][N], pw[MD][N];

struct RollingHash{
    int n;

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();

        rep(i,MD){
            hs[i][0] = 0;
            pw[i][0] = 1;
            rep(j,n){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i] + hash_mod[i]) % hash_mod[i];
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

    // vl calc(int l, int r){
    //     vl ret(MD);
    //     rep(i,MD) ret[i] = hash_value(l-1,r,i);
    //     return ret;
    // }
};

unordered_set<ll> S[N];

const int mod = 1e9+7;
ll dp[N] = {};

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin >>n;

    vector<int> L;
    rep(i,n)
    {
        string s;
        cin >>s;

        int len = s.size();
        RollingHash tmp(s);

        S[len].insert(tmp.calc(1,len));
        L.push_back(len);
    }

    sort(all(L));
    L.erase(unique(all(L)),L.end());

    string t;
    cin >>t;

    RollingHash h(t);
    int T = t.size();

    dp[0] = 1;
    rep(i,T)if(dp[i]!=0)
    {
        dp[i] %= mod;
        rep(j,L.size())
        {
            int nx = i+L[j];
            if(nx>T) break;

            if(S[L[j]].count(h.calc(i+1,nx))) dp[nx] += dp[i];
        }
    }

    cout << dp[T]%mod << endl;
    return 0;
}
