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

ll p[40]={};

const int M = 1<<20;
int dp[M]={};

int main()
{
    int n,m;
    cin >>n >>m;
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        --a;
        --b;

        p[a] |= (1LL<<b);
        p[b] |= (1LL<<a);
    }

    int A = n/2, B = n-A;
    rep(mask,1<<A)
    {
        bool ok = true;
        rep(i,A)if(mask>>i&1)
        {
            if((p[i]&mask)!=0) ok = false;
        }

        if(ok) dp[mask] = __builtin_popcount(mask);
    }

    rep(mask,1<<A)
    {
        rep(i,A)if(!(mask>>i&1))
        {
            int nmask = mask|(1<<i);
            dp[nmask] = max(dp[nmask],dp[mask]);
        }
    }

    int ans = 0;
    for(ll mask=0; mask<(1<<B); ++mask)
    {
        bool ok = true;
        ll b_or = 0;

        rep(i,B)if(mask>>i&1)
        {
            if((p[A+i]&(mask<<A))!=0) ok = false;
            b_or |= p[A+i];
        }
        if(!ok) continue;

        int a_mask = 0;
        rep(i,A)
        {
            if((b_or>>i&1)==0) a_mask|=(1<<i);
        }

        ans = max(ans, dp[a_mask]+__builtin_popcount(mask));
    }

    cout << ans << endl;
    return 0;
}
