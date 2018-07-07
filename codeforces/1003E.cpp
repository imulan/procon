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
using P = pair<int,pi>;

void solve(){
    int n,d,k;
    scanf(" %d %d %d", &n, &d, &k);

    if(n<d+1){
        printf("NO\n");
        return;
    }

    if(d==1){
        if(n==2){
            printf("YES\n1 2\n");
        }
        else printf("NO\n");
        return;
    }

    // d >= 2
    if(k==1){
        printf("NO\n");
        return;
    }

    vector<pi> e;
    for(int i=1; i<=d; ++i) e.pb({i,i+1});

    // (par, (hand,depth))
    queue<P> que;
    for(int i=2; i<=d; ++i){
        int dist = min(d+1-i, i-1);
        if(k-2>0) que.push({i, {k-2, dist}});
    }

    int now = d+2;
    while(now<=n){
        if(que.empty()) break;

        P p = que.front();
        que.pop();

        int u = p.fi;
        int dep = p.se.se;
        e.pb({u,now});

        --p.se.fi;
        if(p.se.fi>0) que.push(p);

        if(dep-1>0){
            P ch = {now, {k-1,dep-1}};
            que.push(ch);
        }

        ++now;
    }

    if(now==n+1){
        printf("YES\n");
        for(const auto &p:e) printf("%d %d\n", p.fi, p.se);
    }
    else printf("NO\n");
}

int main(){
    solve();
    return 0;
}
