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

const char b = 'a'-1;

int n;
string s[50];

ll dp[25][51][51][27];
ll dfs(int d, int l, int r, int a){
    bool all_blank = true;
    for(int i=l; i<r; ++i)if(s[i][d]!=b) all_blank = false;
    if(all_blank) return r-l<=1;

    if(a == 27) return l==r;
    if(l==r) return 1;
    if(dp[d][l][r][a]>=0) return dp[d][l][r][a];

    int cpos = r, bpos = l-1;
    for(int i=l; i<r; ++i){
        if(s[i][d]==b) bpos = max(bpos,i);
        else cpos = min(cpos,i);
    }
    if(cpos < bpos) return 0;

    char c = b+a;
    ll ret = 0;
    for(int i=l; i<=r; ++i){
        (ret += (dfs(d+1,l,i,0)*dfs(d,i,r,a+1))%mod ) %= mod;
        if(i<r){
            if( (s[i][d]!=c && s[i][d]!='?') || (s[i][d]=='?' && c==b) ) break;
        }
    }
    return dp[d][l][r][a] = ret;
}

int main(){
    cin >>n;
    rep(i,n){
        cin >>s[i];
        while(s[i].size()<21) s[i] += b;
    }

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,n,0) << endl;
    return 0;
}
