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

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    int n,q;
    cin >>n >>q;

    vector<vector<int>> p(n);
    rep(i,q){
        int l,r;
        cin >>l >>r;
        --l;
        --r;
        for(int j=l; j<=r; ++j) p[j].pb(i);
    }

    int zero = 0;

    vector<int> S(q);
    map<pair<int,int>,int> P;
    rep(i,n){
        if(p[i].size()==0) ++zero;
        else if(p[i].size()==1) ++S[p[i][0]];
        else if(p[i].size()==2){
            int u = p[i][0], v = p[i][1];
            ++P[{u,v}];
        }
    }

    int ans = 0;
    rep(j,q)rep(i,j){
        int t = n-zero-S[i]-S[j];
        if(P.count({i,j})) t -= P[{i,j}];
        ans = max(ans, t);
    }

    cout << ans << "\n";
    return 0;
}
