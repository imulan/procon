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

int solve()
{
    int n,k;
    cin >>n >>k;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    sort(all(s), [](const string &a, const string &b){return (a.size()<b.size());});

    set<vector<ll>> now;
    rep(i,n)
    {
        RollingHash h(s[i]);
        int L = s[i].size();
        for(int j=1; j<=L; ++j)
        {
            vector<ll> v = h.calc(1,j);
            if(now.count(v)) now.erase(v);
        }
        now.insert(h.calc(1,L));

        if(now.size()==k) return L;
    }
    return -1;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
