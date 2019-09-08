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
    int l[2],r[2];
    rep(i,2) scanf(" %d %d", &l[i], &r[i]);

    for(int i:{l[0],r[0]})for(int j:{l[1],r[1]}){
        if(i!=j){
            printf("%d %d\n",i,j);
            return;
        }
    }
    assert(false);
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) solve();
    return 0;
}
