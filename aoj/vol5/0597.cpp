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

const int P = 5040;
int dp[110][P]={};

int fact[8];

inline vector<int> decode(int x)
{
    vector<int> ret(7);
    vector<bool> use(7,false);
    rep(i,7)
    {
        int num = x/fact[6-i];
        x -= fact[6-i]*num;

        int y = 0,ct = 0;
        while(y<7)
        {
            if(!use[y]) ++ct;

            if(ct==num+1) break;
            ++y;
        }
        use[y]=true;
        ret[i]=y;
    }
    return ret;
}

inline int encode(const vector<int> &p)
{
    int ret = 0;
    vector<bool> use(7,false);
    rep(i,7)
    {
        int ct = 0;
        for(int j=0; j<p[i]; ++j) ct += !use[j];
        ret += ct*fact[6-i];
        use[p[i]]=true;
    }

    return ret;
}

inline vector<int> normalize(const vector<int> &p)
{
    vector<int> t(p);
    sort(all(t));

    int ct=0;
    int id[10];
    for(const auto &v:t) id[v]=ct++;

    vector<int> ret(7);
    rep(i,7) ret[i]=id[p[i]];

    return ret;
}

int main()
{
    fact[0]=1;
    for(int i=1; i<8; ++i) fact[i] = fact[i-1]*i;

    int n;
    cin >>n;
    vector<int> d(n+7),a(n+7);
    rep(i,n) cin >>d[i+7];
    rep(i,n) cin >>a[i+7];

    n += 7;
    for(int i=7; i<n; ++i)rep(j,P)
    {
        vector<int> p = decode(j);

        // i番目を何番目に食べるか
        rep(k,8)
        {
            vector<int> nx(all(p));
            for(auto &v:nx)if(v>=k) ++v;
            nx.pb(k);

            int NX = nx.size();
            int add = 0;
            for(int l=1; l<NX; ++l)
            {
                if(nx[NX-1]>nx[NX-1-l])
                {
                    // i番目より前に食べてる
                    if(d[i-l]>=l) add+=a[i-l];
                }
                else
                {
                    // i番目より後に食べてる
                    if(d[i]>=l && i-l>=7) add+=a[i];
                }
            }

            nx.erase(nx.begin());
            nx = normalize(nx);
            int idx = encode(nx);
            dp[i+1][idx] = max(dp[i+1][idx], dp[i][j]+add);
        }
    }

    cout << *max_element(dp[n],dp[n]+P) << endl;
    return 0;
}
