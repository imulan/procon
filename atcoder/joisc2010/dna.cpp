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

const int N=150150;
const int INF=364364;
int dp[N];

inline ll f(char c)
{
    if(c=='A') return 1;
    if(c=='T') return 2;
    if(c=='G') return 3;
    if(c=='C') return 4;
    assert(false);
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    string s;
    cin >>n >>s;

    ll v;
    unordered_set<ll> h;
    rep(i,n)
    {
        string t;
        cin >>t;

        v = 0;
        rep(j,t.size()) v = (v<<3)|f(t[j]);
        h.insert(v);
    }

    int S = s.size();

    fill(dp,dp+N,INF);
    v = 0;
    for(int i=1; i<=min(20,S); ++i)
    {
        v = (v<<3)|f(s[i-1]);
        if(h.count(v)) dp[i]=1;
    }

    for(int i=1; i<S; ++i)if(dp[i]!=INF)
    {
        for(int j=i+1; j<=min(S,i+19); ++j)
        {
            if(dp[j]<=dp[i]+1) continue;

            v = f(s[j-1]);
            ll shift = 3;
            for(int k=2; k<=20; ++k)
            {
                if(j-k+1<1) break;
                v |= (f(s[j-k])<<shift);
                shift += 3;

                if(j-k>i-1) continue;

                if(h.count(v))
                {
                    dp[j] = min(dp[j],dp[i]+1);
                    break;
                }
            }
        }
    }

    printf("%d\n", dp[S]);
    return 0;
}
