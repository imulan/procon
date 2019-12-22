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

const int N = 500005;
vector<int> pos[N];

int main(){
    int n,c;
    scanf(" %d %d", &n, &c);

    rep(i,n){
        int a;
        scanf(" %d", &a);
        pos[a].pb(i);
    }

    vector<int> pre(n+1);
    for(int i:pos[c]) ++pre[i+1];
    rep(i,n) pre[i+1] += pre[i];

    int ct_c = pos[c].size();
    int ans = ct_c;
    rep(i,N)if(i!=c){
        int sz = pos[i].size();
        if(sz<=1){
            ans = max(ans, ct_c+sz);
            continue;
        }

        vector<int> x;
        rep(j,sz-1){
            x.pb(1);
            int l = pos[i][j], r = pos[i][j+1];
            x.pb(-(pre[r+1] - pre[l]));
        }
        x.pb(1);

        int mx = -n;
        int y = 0;
        for(int j:x){
            y = max(0, y+j);
            mx = max(mx,y);
        }
        ans = max(ans, ct_c+mx);
    }
    printf("%d\n", ans);
    return 0;
}
