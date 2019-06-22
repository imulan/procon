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

const int INF = 19191919;

int main(){
    int n,L;
    cin >>n >>L;

    int s = 0;
    for(int i=1; i<=n; ++i) s += L+i-1;

    int d = INF;
    int ans = INF;
    for(int i=1; i<=n; ++i){
        int x = 0;
        for(int j=1; j<=n; ++j)if(i!=j) x += L+j-1;

        int t = abs(x - s);
        if(t < d){
            ans = x;
            d = t;
        }
    }

    cout << ans << endl;
    return 0;
}
