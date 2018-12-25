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

// (top,front)
int R[7][7]={
    {-1, -1, -1, -1, -1, -1, -1},
    {-1, -1,  3,  5,  2,  4, -1},
    {-1,  4, -1,  1,  6, -1,  3},
    {-1,  2,  6, -1, -1,  1,  5},
    {-1,  5,  1, -1, -1,  6,  2},
    {-1,  3, -1,  6,  1, -1,  4},
    {-1, -1,  4,  2,  5,  3, -1},
};

using vi = vector<int>;
using vvi = vector<vi>;
const vvi I(3,vi(3));

vvi T,F;
vvi t,f;
vector<int> ans;

void check(){
    vvi r(I);
    int rsum = 0;
    rep(i,3)rep(j,3){
        r[i][j] = R[T[j][0]][F[i][0]];
        if(r[i][j]==-1) return;
        rsum += r[i][j];
    }

    rep(fi,3)rep(fj,3){
        if(f[fi][fj]==0){
            for(int i=1; i<=6; ++i){
                if(R[t[0][fj]][i] == r[fi][0]){
                    f[fi][fj] = i;
                }
            }

            if(f[fi][fj]==0) return;
        }
    }

    rep(ti,3)rep(tj,3){
        if(t[ti][tj]==0){
            for(int i=1; i<=6; ++i){
                if(R[i][f[0][tj]] == r[0][ti]){
                    t[ti][tj] = i;
                }
            }

            if(t[ti][tj]==0) return;
        }
    }


    rep(ti,3)rep(fi,3)rep(x,3){
        int rv = r[fi][ti];
        if(R[t[ti][x]][f[fi][x]] != rv) return;
    }

    ans.pb(rsum);
}

void dfs(int d){
    if(d==8){
        t = T;
        f = F;
        check();
        return;
    }

    if(d<3){
        if(T[d][0]==0){
            for(int i=1; i<=6; ++i){
                T[d][0] = i;
                dfs(d+1);
                T[d][0] = 0;
            }
        }
        else dfs(d+1);
    }
    else if(d<6){
        if(F[d-3][0]==0){
            for(int i=1; i<=6; ++i){
                F[d-3][0] = i;
                dfs(d+1);
                F[d-3][0] = 0;
            }
        }
        else dfs(d+1);
    }
    else{
        if(T[0][d-5]==0){
            for(int i=1; i<=6; ++i){
                T[0][d-5] = i;
                dfs(d+1);
                T[0][d-5] = 0;
            }
        }
        else dfs(d+1);
    }
}

void solve(){
    T = I;
    F = I;
    rep(i,3)rep(j,3) cin >>T[i][j];
    rep(i,3)rep(j,3) cin >>F[i][j];

    ans.clear();
    dfs(0);

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    int n = ans.size();
    if(n==0) cout << 0 << endl;
    else rep(i,n) cout << ans[i] << " \n"[i==n-1];
}

int main(){
    int n;
    cin >>n;
    rep(i,n) solve();
    return 0;
}
