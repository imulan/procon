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

void solve(){
    int n;
    scanf(" %d", &n);
    vector<int> v(n);
    rep(i,n) scanf(" %d", &v[i]);

    vector<int> e[2];
    rep(i,n) e[i%2].pb(v[i]);

    rep(i,2) sort(all(e[i]));

    vector<int> x;
    rep(i,e[1].size()){
        x.pb(e[0][i]);
        x.pb(e[1][i]);
    }
    if(n%2==1) x.pb(e[0][e[0].size()-1]);

    assert(x.size()==n);
    rep(i,n){
        if(i-1>=0 && x[i-1]>x[i]){
            printf("%d\n", i);
            return;
        }
        if(i+1<n && x[i]>x[i+1]){
            printf("%d\n", i);
            return;
        }
    }

    printf("OK\n");
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
