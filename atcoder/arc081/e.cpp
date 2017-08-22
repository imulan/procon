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

const int INF = 123456789;

vector<int> p[26];
int next(int idx, char c)
{
    int id = c-'a';
    return *lower_bound(all(p[id]),idx);
}

int main()
{
    string a;
    cin >>a;
    int A = a.size();

    rep(i,A) p[a[i]-'a'].pb(i);
    rep(i,26) p[i].pb(A);

    vector<int> dp(A+2,INF);
    vector<int> par(A+2,INF);
    dp[A+1] = 0;
    for(int i=A-1; i>=0; --i)
    {
        rep(j,26)
        {
            int nidx = next(i,'a'+j)+1;
            // printf(" (%d %d)  %d\n", i,j,nidx);

            if(dp[i]>dp[nidx]+1)
            {
                dp[i] = dp[nidx]+1;
                par[i] = nidx;
            }
        }
    }

    // dbg(dp);
    // dbg(par);

    string ans = "";
    int now = 0;
    while(par[now]!=INF)
    {
        rep(i,26)
        {
            char c = i+'a';

            if(next(now,c)+1==par[now])
            {
                ans += c;
                now = next(now,c)+1;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
