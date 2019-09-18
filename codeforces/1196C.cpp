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

const int W = 100000;

void solve(){
    int n;
    scanf(" %d", &n);

    int X[2],Y[2];
    rep(i,2){
        int m = i?1:-1;
        X[i] = Y[i] = m*W;
    }

    rep(pp,n){
        int x,y;
        scanf(" %d %d", &x, &y);

        rep(i,4){
            int f;
            scanf(" %d", &f);
            if(!f){
                if(i==0) X[0] = max(X[0], x);
                else if(i==1) Y[1] = min(Y[1], y);
                else if(i==2) X[1] = min(X[1], x);
                else Y[0] = max(Y[0], y);
            }
        }
    }

    if(X[0]<=X[1] && Y[0]<=Y[1]) printf("1 %d %d\n", X[0], Y[0]);
    else printf("0\n");
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) solve();
    return 0;
}
