// TLE

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
RollingHash rh[N];
int sz[N];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;

    rep(i,n)
    {
        string s;
        cin >>s;
        rh[i] = RollingHash(s);
        sz[i] = s.size();
    }

    int m;
    ll x,d;
    cin >>m >>x >>d;

    ll ans=0;
    while(m--)
    {
        // make query
        ll u=x/(n-1), v=x%(n-1);
        if(u>v) swap(u,v);
        else ++v;
        x = (x+d)%((ll)n*(n-1));

        // printf("u,v %lld, %lld\n", u,v);

        // solve
        int l=0, r=min(sz[u],sz[v])+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;

            if(rh[u].calc(1,mid) == rh[v].calc(1,mid)) l=mid;
            else r=mid;
        }

        ans += l;
    }

    cout << ans << endl;
    return 0;
}
