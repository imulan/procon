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
    int n,m;
    double p;
    cin >>n >>m >>p;

    vector<int> u(m),v(m);
    rep(i,m){
        cin >>u[i] >>v[i];
        --u[i];
        --v[i];
    }

    p /= 100.0;

    vector<double> pw(m+1);
    pw[0] = 1;
    rep(i,m) pw[i+1] = pw[i]*p;

    vector<double> dp(1<<n);
    rep(mask,1<<n){
        dp[mask] = 1;

        int sub = mask;
        while(1){
            sub = (sub-1)&mask;
            if(sub == 0) break;
            if(sub%2!=1) continue;

            int o_mask = mask^sub;

            int ct = 0;
            rep(i,m){
                if(sub>>u[i]&1){
                    if(o_mask>>v[i]&1) ++ct;
                }
                if(sub>>v[i]&1){
                    if(o_mask>>u[i]&1) ++ct;
                }
            }

            dp[mask] -= dp[sub]*pw[ct];
        }
    }

    cout << fixed << setprecision(15) << dp[(1<<n)-1] << endl;
    return 0;
}
