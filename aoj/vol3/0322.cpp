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

    vector<ll> calc(int l, int r){
        vector<ll> ret(MD);
        rep(i,MD) ret[i]=hash_value(l-1,r,i);
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{1009,1021};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007};

using P = pair<string,int>;
vector<P> query[201];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n,m;
    cin >>n >>m;

    vector<int> dl(n);
    vector<RollingHash> d(n);
    rep(i,n)
    {
        string word;
        cin >>word;
        d[i] = RollingHash(word);
        dl[i] = word.size();
    }
    rep(i,m)
    {
        string slate;
        cin >>slate;
        int S = slate.size();
        query[S].pb({slate,i});
    }


    vector<int> ans(m);

    for(int L=1; L<=200; ++L)
    {
        map<vector<ll>,int> pre,suf,whole;
        rep(i,n)
        {
            if(dl[i]==L) ++whole[d[i].calc(1,L)];
            if(dl[i]>=L-1)
            {
                ++pre[d[i].calc(1,L-1)];
                ++suf[d[i].calc(dl[i]-L+2,dl[i])];
            }
        }

        for(const auto &p:query[L])
        {
            string slate = p.fi;
            int ID = p.se;

            int S = slate.size();
            int ct = 0;

            int q = -1;
            rep(i,S)if(slate[i]=='?') q=i;

            int LIM = 26;
            if(q==-1) LIM = 1;
            rep(i,LIM)
            {
                if(q!=-1) slate[q] = 'a'+i;

                if(slate[0]=='*')
                {
                    // suf
                    RollingHash h(slate.substr(1));
                    vector<ll> val = h.calc(1,S-1);
                    if(suf.count(val)) ct += suf[val];
                }
                else if(slate[S-1]=='*')
                {
                    // pre
                    RollingHash h(slate.substr(0,S-1));
                    vector<ll> val = h.calc(1,S-1);
                    if(pre.count(val)) ct += pre[val];
                }
                else
                {
                    // whole
                    RollingHash h(slate);
                    vector<ll> val = h.calc(1,S);
                    if(whole.count(val)) ct += whole[val];
                }
            }

            ans[ID] = ct;
        }
    }

    rep(i,m) cout << ans[i] << '\n';
    return 0;
}
