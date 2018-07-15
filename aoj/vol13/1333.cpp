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
    int w,n;
    while(cin >>w >>n,w){
        vector<int> x(n+1);
        rep(i,n) cin >>x[i+1];

        vector<ll> pre(n+1);
        for(int i=1; i<=n; ++i) pre[i] = pre[i-1]+x[i];

        auto check = [&](ll m){
            vector<int> dp(n+2);
            dp[1] = 1;

            int ct = 0;
            int L=1,R=1;
            // 右端i
            for(int i=2; i<=n; ++i){
                while(1){
                    if(R==i) break;
                    ll t = pre[i]-pre[R-1]+m*(i-R);
                    if(t>=w){
                        ct += dp[R];
                        ++R;
                    }
                    else break;
                }

                while(1){
                    if(L==i) break;
                    ll t = pre[i]-pre[L-1]+(i-L);
                    if(t>w){
                        ct -= dp[L];
                        ++L;
                    }
                    else break;
                }

                dp[i+1] = (ct>0);
            }

            if(dp[n+1]) return true;
            for(int i=n; i>0; --i){
                // dbg(i);
                ll t = pre[n]-pre[i-1]+n-i;
                if(t<=w && dp[i]) return true;
            }
            return false;
        };

        int l=0, r=w;
        while(r-l>1){
            int m = (l+r)/2;
            if(check(m)) r = m;
            else l = m;
        }
        printf("%d\n",r);
    }
    return 0;
}
