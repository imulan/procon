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

int main()
{
    int n;
    cin >>n;

    vector<string> ok,ng;
    rep(i,n)
    {
        char c;
        string s;
        cin >>c >>s;
        if(c=='-') ng.pb(s);
        else ok.pb(s);
    }

    // filterに入れてはいけないものを列挙
    set<vector<ll>> OK;
    rep(i,ok.size())
    {
        RollingHash rh(ok[i]);
        int S=ok[i].size();
        rep(j,S) OK.insert(rh.calc(1,j+1));
    }

    bool valid=true;
    set<string> ans;
    rep(i,ng.size())
    {
        RollingHash rh(ng[i]);

        if(OK.find(rh.calc(1,ng[i].size())) != OK.end())
        {
            valid=false;
            break;
        }

        if(OK.find(rh.calc(1,1)) == OK.end())
        {
            ans.insert(ng[i].substr(0,1));
        }
        else
        {
            int l=1, r=ng[i].size();
            while(r-l>1)
            {
                int m=(l+r)/2;
                if(OK.find(rh.calc(1,m)) == OK.end()) r=m;
                else l=m;
            }
            ans.insert(ng[i].substr(0,r));
        }
    }

    if(valid)
    {
        cout << ans.size() << endl;
        for(const auto &x:ans) cout << x << endl;
    }
    else cout << -1 << endl;
    return 0;
}
