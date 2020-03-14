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

const int N = 20000;

void solve(){
    vector<int> v(3);
    rep(i,3) scanf(" %d", &v[i]);

    vector<int> a(3);
    int mn = 19191919;
    for(int i=1; i<=N; ++i){
        for(int j=i; j<=N; j+=i){
            for(int k=j; k<=N; k+=j){
                int c = abs(i-v[0])+abs(j-v[1])+abs(k-v[2]);
                if(mn > c){
                    mn = c;
                    a = {i,j,k};
                }
            }
        }
    }

    printf("%d\n", mn);
    rep(i,3) printf("%d%c", a[i], " \n"[i==2]);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
