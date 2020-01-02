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

int solve(){
    int v[3];
    rep(i,3) scanf(" %d", &v[i]);
    sort(v,v+3);

    if(v[2] > v[0]+v[1]) return v[0]+v[1];

    int sv = 0;
    rep(i,3) sv += v[i];
    return sv/2;
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--) printf("%d\n", solve());
    return 0;
}
