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

using vi = vector<int>;

const int mod=1e9+7;

int n,X,P;
int a[50];

int dp[51][180000]={};
int NMASK[177147][11];

inline vi construct(int mask)
{
    vi ret(X+1);
    rep(i,X+1)
    {
        ret[i]=mask%3;
        mask/=3;
    }
    return ret;
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    cin >>n >>X >>P;

    int pw=1;
    rep(i,X+1) pw*=3;

    rep(i,n)
    {
        string s;
        cin >>s;

        if(s=="?") a[i]=-1;
        else a[i]=atoi(s.c_str());
    }

    rep(mask,pw)
    {
        vi x = construct(mask);
        rep(j,P+1)
        {
            int nmask = 0;
            int POW=1;
            rep(k,X+1)
            {
                int y=0;
                if(k-j>=0) y+=x[k-j];
                y = min(y+x[k],2);

                nmask+=y*POW;
                POW*=3;
            }
            NMASK[mask][j] = nmask;
        }
    }

    dp[0][1]=1;
    rep(i,n)rep(mask,pw)
    {
        vi x = construct(mask);
        if(x[X]==2) continue;

        int l=0, r=P;
        if(a[i]!=-1) l=r=a[i];

        // a[i]に選ぶ数 = j
        for(int j=l; j<=r; ++j)
        {
            int nmask = NMASK[mask][j];
            (dp[i+1][nmask]+=dp[i][mask])%=mod;
        }
    }

    int ans = 0;
    rep(i,pw)
    {
        vi mask = construct(i);
        if(mask[X]==1) (ans+=dp[n][i])%=mod;
    }

    printf("%d\n", ans);
    return 0;
}
