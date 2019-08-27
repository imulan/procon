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

void solve(){
    int n;
    scanf(" %d", &n);
    vector<int> x(n);
    rep(i,n){
        int a;
        scanf(" %d", &a);
        ++x[a-1];
    }
    sort(all(x), greater<int>());

    int idx = 0;
    int s = 0;
    for(int i=n; i>0; --i){
        if(idx<n && x[idx]>=i){
            ++idx;
            s += i;
        }
    }
    printf("%d\n", s);
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) solve();
    return 0;
}
