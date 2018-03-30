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

const int N = 20;
int a[N];

ll dp[N][2][5][2];
// no, 5, 51, 51(5以外), 515,
ll dfs(int d, int small, int state, int g){
    if(d==N){
        return g;
    }
    if(dp[d][small][state][g]>=0) return dp[d][small][state][g];

    int lim = 9;
    if(small==0) lim = a[d];

    ll ret = 0;
    for(int i=0; i<=lim; ++i){
        int ns = small|(i<a[d]);
        int nx = 0;
        int ng = g;
        if(i==1){
            if(state==1 || state==4) nx = 2;
            if(state==2) nx = 3;
        }
        else if(i==3){
            if(state==2) nx = 3;
            if(state==3 || state==4) ng = 1;
        }
        else if(i==5){
            if(state==2) nx = 4;
            else nx = 1;
        }
        else{
            if(state==2) nx = 3;
        }

        ret += dfs(d+1, ns, nx, ng);
    }

    return dp[d][small][state][g] = ret;
}

int main(){
    ll n;
    cin >>n;

    for(int i=N-1; i>=0; --i){
        a[i] = n%10;
        n/=10;
    }

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0,0) << endl;
    return 0;
}
