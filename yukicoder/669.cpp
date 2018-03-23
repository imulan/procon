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

const int N = 1000001;
int dp[N];
int ct[N];

int g(int n, int k){
    if(dp[n]>=0) return dp[n];

    vector<int> v;
    for(int i=1; i<=k; ++i){
        int r = n-i;
        if(r<0) break;
        ++ct[g(r,k)];
    }

    int ret = 0;
    while(ct[ret]!=0) ++ret;

    for(int i=1; i<=k; ++i){
        int r = n-i;
        if(r<0) break;
        --ct[g(r,k)];
    }

    return dp[n] = ret;
}

void test(int n, int k){
    memset(dp,-1,sizeof(dp));
    rep(i,n+1){
        printf(" g(%d) = %d :: %d\n",i,g(i,k), i%(k+1));
    }
}

int main(){
    int n,k;
    cin >>n >>k;
    // test(n,k);

    int x = 0;
    rep(i,n){
        int a;
        cin >>a;
        x ^= a%(k+1);
    }

    cout << (x==0?"NO":"YES") << endl;
    return 0;
}
