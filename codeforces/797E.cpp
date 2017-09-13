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

using pi = pair<int,int>;
using P = pair<pi,int>;

int n;
int a[100001];

const int LIM = 320;
int dp[LIM][100001];
int calc(int p, int k)
{
    if(p>n) return 0;

    if(k<LIM)
    {
        if(dp[k][p]>0) return dp[k][p];
        return dp[k][p] = 1+calc(p+a[p]+k,k);
    }
    else return 1+calc(p+a[p]+k,k);
}

int main()
{
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i+1]);

    int q;
    scanf(" %d", &q);

    memset(dp,-1,sizeof(dp));
    while(q--)
    {
        int p,k;
        scanf(" %d %d", &p, &k);
        printf("%d\n", calc(p,k));
    }
    return 0;
}
