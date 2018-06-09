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

const int N = 55;
const int INF = 123456789;

int n,m;
int a[N],b[N];

int dp[N][N][N][N][2][2];
int dfs(int as, int ad, int bs, int bd, int t, int p){
    if(dp[as][ad][bs][bd][t][p] > -2*INF) return dp[as][ad][bs][bd][t][p];

    int ret;
    if(t==0){
        ret = -INF;

        // card
        if(ad<n){
            ret = max(ret, dfs(as,ad+1,bs,bd,!t,0));
        }

        // pass
        if(p==1){
            ret = max(ret, 0);
        }
        else{
            if(as==ad && bs==bd){
                ret = max(ret, dfs(ad,ad,bd,bd,!t,1));
            }
            else{
                int add = 0;
                int aidx = ad-1, bidx = bd-1;
                bool aflg = false, bflg = false;
                while(1){
                    if(bidx<bs) break;
                    if(b[bidx] == -1) bflg = true;
                    else{
                        if(!aflg) add -= b[bidx];
                    }
                    --bidx;

                    if(aidx<as) break;
                    if(a[aidx] == -1) aflg = true;
                    else{
                        if(!bflg) add += a[aidx];
                    }
                    --aidx;
                }
                ret = max(ret, dfs(ad,ad,bd,bd,!t,0) + add);
            }
        }
    }
    else{
        ret = INF;

        // card
        if(bd<m){
            ret = min(ret, dfs(as,ad,bs,bd+1,!t,0));
        }

        // pass
        if(p==1){
            ret = min(ret, 0);
        }
        else{
            if(as==ad && bs==bd){
                ret = min(ret, dfs(ad,ad,bd,bd,!t,1));
            }
            else{
                int add = 0;
                int aidx = ad-1, bidx = bd-1;
                bool aflg = false, bflg = false;
                while(1){
                    if(aidx<as) break;
                    if(a[aidx] == -1) aflg = true;
                    else{
                        if(!bflg) add += a[aidx];
                    }
                    --aidx;

                    if(bidx<bs) break;
                    if(b[bidx] == -1) bflg = true;
                    else{
                        if(!aflg) add -= b[bidx];
                    }
                    --bidx;
                }
                ret = min(ret, dfs(ad,ad,bd,bd,!t,0) + add);
            }
        }
    }

    // printf(" %d %d %d %d %d %d:: %d\n",as,ad,bs,bd,t,p,ret);
    return dp[as][ad][bs][bd][t][p] = ret;
}

int main(){
    cin >>n >>m;
    rep(i,n) cin >>a[i];
    rep(i,m) cin >>b[i];

    rep(i,N)rep(j,N)rep(k,N)rep(l,N)rep(tt,2)rep(pp,2) dp[i][j][k][l][tt][pp] = -2*INF;
    cout << dfs(0,0,0,0,0,0) << endl;
    return 0;
}
