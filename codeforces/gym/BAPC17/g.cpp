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

int main(){
    int m,n;
    cin >>m >>n;

    vector<int> x(m);
    rep(i,n){
        int a,b,p;
        cin >>a >>b >>p;
        x[a] += p;
        x[b] -= p;
    }

    int M = 1<<m;
    vector<int> dp(M);
    rep(mask,M){
        int sum = 0;
        rep(i,m)if(mask>>i&1) sum += x[i];

        rep(i,m)if(!(mask>>i&1)){
            int nmask = mask|(1<<i);
            int add = (sum+x[i]==0);
            dp[nmask] = max(dp[nmask], dp[mask]+add);
        }
    }
    cout << m-dp[M-1] << endl;
    return 0;
}
