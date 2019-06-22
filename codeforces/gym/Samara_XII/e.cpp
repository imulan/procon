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
using P = pair<pi,int>;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<P> v(n);
    rep(i,n){
        int a,b;
        scanf(" %d %d", &a, &b);
        v[i] = {{a,b},i};
    }
    sort(all(v));

    priority_queue<pi> pq;
    vector<int> ans;
    int s = 1;
    int idx = 0;
    while(s<=m){
        while(idx<n && v[idx].fi.fi<=s){
            pq.push({v[idx].fi.se, v[idx].se});
            ++idx;
        }
        if(pq.empty()) break;

        pi x = pq.top();
        pq.pop();

        ans.pb(x.se);
        s = max(s,x.fi+1);
    }

    if(s > m){
        printf("YES\n");
        int A = ans.size();
        printf("%d\n", A);
        rep(i,A) printf("%d%c", ans[i]+1, " \n"[i==A-1]);
    }
    else printf("NO\n");
    return 0;
}
