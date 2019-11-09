#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 1000;
int a[N][N];

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n)rep(j,n-1){
        scanf(" %d", &a[i][j]);
        --a[i][j];
    }

    vector<int> cand;
    rep(i,n) cand.pb(i);

    vector<int> x(n);
    int ans = 0;
    while(1){
        bool upd = false;

        vector<int> nx;
        vector<bool> used(n);
        for(int i:cand)if(!used[i] && x[i]<n-1){
            int e = a[i][x[i]];
            if(!used[e] && x[e]<n-1 && a[e][x[e]]==i){
                // dbg(((pair<int,int>){i,e}));
                used[i] = used[e] = true;
                ++x[i];
                ++x[e];
                nx.pb(i);
                nx.pb(e);
                upd = true;
            }
        }

        if(!upd) break;
        cand = nx;
        ++ans;
    }

    rep(i,n)if(x[i]!=n-1) ans = -1;

    printf("%d\n", ans);
    return 0;
}
