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

const int C = 2540;

const int N = 100000;
map<int,int> G[N];

int main(){
    int n,m;
    cin >>n >>m;

    vector<int> a(m),b(m),L(m);
    rep(i,m){
        cin >>a[i] >>b[i] >>L[i];
        --a[i];
        --b[i];
        ++G[a[i]][L[i]];
        ++G[b[i]][L[i]];
    }

    ll ans = 0;
    rep(i,m){
        int key = C - L[i];

        ans += G[a[i]][key];
        if(key == L[i]) --ans;

        ans += G[b[i]][key];
        if(key == L[i]) --ans;
    }
    ans/=2;
    cout << ans << endl;
    return 0;
}
