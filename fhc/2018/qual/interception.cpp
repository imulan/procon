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
    cin >>n;
    vector<int> p(n+1);
    rep(i,n+1) cin >>p[i];

    if(n%2==1) printf(" 1\n0\n");
    else printf(" 0\n");
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d:", i+1);
        solve();
    }
    return 0;
}
