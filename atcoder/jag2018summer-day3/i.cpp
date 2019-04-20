#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

vector<int> divisor(int x){
    vector<int> r;
    for(int i=1; i*i<=x; ++i){
        if(x%i==0){
            r.pb(i);
            if(i != x/i) r.pb(x/i);
        }
    }
    sort(all(r));
    return r;
}

const int N = 100010;
ll dp[N];

ll f(int x){
    if(dp[x]>=0) return dp[x];

    ll ret = 0;
    for(int i=1; i<1000; ++i){
        if(i%2==1){
            if(x%i!=0) continue;
            int start = x/i - i/2;
            if(start>0) ++ret;
        }
        else{
            int p = i/2;
            if(x%p!=0) continue;

            int start = x/p+1-i;
            if(start<=0 || start%2!=0) continue;

            // printf("%d : st %d\n",i,start);
            if(start>0) ++ret;
        }
    }

    // printf(" x %d : %lld\n",x,ret);
    return dp[x] = ret;
}

int main(){
    int S;
    cin >>S;

    vector<int> d = divisor(S);

    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    for(int i:d){
        ans += f(i)*f(S/i);
    }
    cout << ans << endl;
    return 0;
}
