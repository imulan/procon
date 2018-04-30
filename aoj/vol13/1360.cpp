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

string d;
int n;
int sumD = 0;
ll prodD = 1;

const int SUM=130;
// unknown, small, large
unordered_map<ll,ll> dp[15][SUM][3];
ll dfs(int x, int sum, int sl, ll prod){
    if(x==n){
        if(sum<sumD) return 1;
        else if(sum==sumD){
            if(prod<prodD) return 1;
            else if(prod==prodD){
                if(sl == 1) return 1;
            }
        }
        return 0;
    }

    if(dp[x][sum][sl].count(prod)) return dp[x][sum][sl][prod];

    ll ret = 0;
    rep(i,10){
        int nsl = sl;
        if(sl==0){
            int v = d[x]-'0';
            if(i<v) nsl = 1;
            if(i>v) nsl = 2;
        }

        ret += dfs(x+1, sum+i, nsl, prod*(i+1));
    }
    return dp[x][sum][sl][prod] = ret;
}

int main(){
    cin >>d;
    n = d.size();

    rep(i,n){
        int v = d[i]-'0';
        sumD += v;
        prodD *= (v+1);
    }

    cout << dfs(0,0,0,1) << endl;
    return 0;
}
