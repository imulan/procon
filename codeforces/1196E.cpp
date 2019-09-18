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
    int b,w;
    scanf(" %d %d", &b, &w);

    pi r = {2,2};
    if(b<=w){
        r = {2,3};
        swap(b,w);
    }

    // w <= b
    if(3*w+1 < b){
        printf("NO\n");
        return;
    }

    vector<pi> W,B;
    pi p = r;
    rep(i,w){
        W.pb(p);
        p.se += 2;
    }

    rep(i,w){
        pi t = W[i];
        ++t.se;
        B.pb(t);
    }
    b -= w;

    if(b>0){
        --b;
        B.pb({r.fi, r.se-1});
    }

    for(int i:{-1,1})rep(j,w){
        if(b>0){
            --b;

            pi t = W[j];
            t.fi += i;
            B.pb(t);
        }
    }

    printf("YES\n");
    for(auto &v:{W,B})for(auto &a:v) printf("%d %d\n", a.fi, a.se);
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) solve();
    return 0;
}
