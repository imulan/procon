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

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a;
    map<int,vector<int>> idx;
    a.pb(-1);
    rep(i,n){
        int t;
        scanf(" %d", &t);
        a.pb(t);
        idx[t].pb(i+1);
    }
    a.pb(-1);

    n += 2;
    vector<bool> sink(n);
    sink[0] = sink[n-1] = true;

    int now = 1;
    if(idx.count(0)){
        for(int i:idx[0]){
            sink[i] = true;
            if(sink[i-1] && sink[i+1]) --now;
            if(!sink[i-1] && !sink[i+1]) ++now;
        }
    }

    int ans = now;
    for(const auto &p:idx){
        if(p.fi == 0) continue;
        for(int i:p.se){
            sink[i] = true;
            if(sink[i-1] && sink[i+1]) --now;
            if(!sink[i-1] && !sink[i+1]) ++now;
        }
        ans = max(ans,now);
    }

    printf("%d\n", ans);
    return 0;
}
