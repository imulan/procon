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
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n) scanf(" %d", &a[i][j]);

    int k=0, r=0, c=0;
    rep(i,n) k += a[i][i];

    rep(i,n){
        set<int> s;
        rep(j,n){
            if(s.count(a[i][j])){
                ++r;
                break;
            }
            s.insert(a[i][j]);
        }
    }
    rep(i,n){
        set<int> s;
        rep(j,n){
            if(s.count(a[j][i])){
                ++c;
                break;
            }
            s.insert(a[j][i]);
        }
    }

    printf("%d %d %d\n", k, r, c);
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
