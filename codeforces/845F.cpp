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

const ll mod = 1e9+7;

ll dp[251][1<<15][2][2]={};

int main()
{
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    if(w>h)
    {
        vector<string> ns(w);
        rep(i,w)
        {
            ns[i]="";
            rep(j,h) ns[i] += s[j][i];
        }
        s = ns;
        swap(h,w);
    }

    dp[0][0][0][0]=1;
    rep(i,h)rep(j,w)rep(mask,1<<w)rep(k,2)rep(l,2)
    {
        int ID=i*w+j;
        if(!dp[ID][mask][k][l]) continue;

        if(s[i][j]=='x')
        {
            int nmask = mask>>1;
            (dp[ID+1][nmask][k][0] += dp[ID][mask][k][l]) %= mod;
        }
        else
        {
            int nmask,nk,nl;

            // place
            nmask = mask>>1;
            nmask |= 1<<(w-1);
            nk = k;
            nl = 1;
            if(j==w-1) nl=0;
            (dp[ID+1][nmask][nk][nl] += dp[ID][mask][k][l]) %= mod;

            // not place
            nmask = mask>>1;
            nk = k;
            nl = l;
            if(j==w-1) nl=0;

            if(mask&1) nmask |= 1<<(w-1);
            else
            {
                if(!l) ++nk;
            }

            if(nk<2) (dp[ID+1][nmask][nk][nl] += dp[ID][mask][k][l]) %= mod;
        }
    }

    ll ans = 0;
    rep(mask,1<<w)rep(i,2)rep(j,2) (ans+=dp[h*w][mask][i][j])%=mod;
    cout << ans << endl;
    return 0;
}
