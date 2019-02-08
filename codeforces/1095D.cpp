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
    int n;
    scanf(" %d", &n);

    vector<vector<int>> p(n);
    rep(i,n){
        rep(j,2){
            int a;
            scanf(" %d", &a);
            --a;
            p[i].pb(a);
        }
    }

    vector<int> ans(n);
    ans[0] = 0;
    rep(i,2){
        int nx = p[0][i];
        int nnx = p[0][!i];

        // nnx appear in nx list?
        bool valid = false;
        rep(j,2)if(p[nx][j] == nnx) valid = true;

        if(valid){
            ans[1] = nx;
            ans[2] = nnx;
            break;
        }
    }

    for(int i=3; i<n; ++i){
        int f = ans[i-2];
        int nx = ans[i-1];
        rep(j,2){
            if(p[f][j] != nx){
                ans[i] = p[f][j];
            }
        }
    }

    rep(i,n) printf("%d%c", ans[i]+1, " \n"[i==n-1]);
    return 0;
}
