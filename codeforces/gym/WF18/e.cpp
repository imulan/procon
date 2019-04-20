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

const int N = 2500;
pi s[N];
int a[N];
int dp[N];

int main(){
    int n;
    scanf(" %d", &n);

    int max_a = 0;
    rep(i,n){
        char ss[88];
        scanf(" %s", ss);
        a[i] = strlen(ss);
        max_a = max(max_a, a[i]);
    }

    int aw = -1, ans = -1;
    for(int w=max_a; w<=202500; ++w){

        int r = 0, c = a[0];
        int S = 0;

        for(int i=1; i<n; ++i){
            if(c + 1 + a[i] <= w){
                s[S] = {r,c};
                ++S;

                c += 1+a[i];
            }
            else{
                ++r;
                c = a[i];
            }
        }

        if(r+1 <= ans) break;

        rep(i,S) dp[i] = 1;

        int tmp = 0;
        int nx = 0;
        rep(i,S){
            while(nx<S){
                if(s[nx].fi > s[i].fi+1) break;
                if(s[nx].fi == s[i].fi+1){
                    if(s[nx].se >= s[i].se-1) break;
                }
                ++nx;
            }

            for(int j=nx; j<=min(nx+1,n-1); ++j){
                if(s[j].fi==s[i].fi+1 && abs(s[j].se-s[i].se)<=1){
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }

            tmp = max(tmp, dp[i]);
        }

        if(tmp > ans){
            ans = tmp;
            aw = w;
        }
    }

    printf("%d %d\n", aw, ans);
    return 0;
}
