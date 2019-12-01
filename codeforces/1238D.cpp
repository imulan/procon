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

int main(){
    int n;
    string s;
    cin >>n >>s;

    vector<int> v;
    int start = 0;
    while(start < n){
        int nx = start;
        while(nx<n && s[nx]==s[start]) ++nx;
        v.pb(nx-start);
        start = nx;
    }

    int V = v.size();

    ll ans = 0;
    int idx = 0;
    rep(i,V){
        int x = v[i];
        int sub = 1;
        if(i==V-1) sub = 0;
        rep(j,x){
            int add = n-1-idx-sub;
            if(j==x-1){
                if(i<V-1) add -= v[i+1]-1;
            }
            // printf(" %d:",idx);dbg(add);
            ans += add;
            ++idx;
        }
    }
    cout << ans << "\n";
    return 0;
}
