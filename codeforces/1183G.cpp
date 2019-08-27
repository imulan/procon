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

using pi = pair<int,int>;

void solve(){
    int n;
    scanf(" %d", &n);

    vector<vector<int>> x(n, vector<int>(2));
    rep(i,n){
        int a,f;
        scanf(" %d %d", &a, &f);
        ++x[a-1][f];
    }

    vector<pi> v(n);
    rep(i,n) v[i] = {x[i][0]+x[i][1], i};
    sort(all(v), greater<pi>());

    // (num f1, index)
    priority_queue<pi> pq;
    int s = 0, f1 = 0;
    int vidx = 0;
    for(int i=n; i>0; --i){
        while(vidx<n && v[vidx].fi>=i){
            int idx = v[vidx].se;
            pq.push({x[idx][1], idx});
            ++vidx;
        }

        if(!pq.empty()){
            pi t = pq.top();
            pq.pop();

            s += i;
            f1 += min(t.fi,i);
        }
    }

    printf("%d %d\n", s, f1);
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) solve();
    return 0;
}
