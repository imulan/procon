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
    int n,k;
    ll v;
    cin >>n >>k >>v;

    vector<string> a(n);
    rep(i,n) cin >>a[i];

    int start = ((v-1)*k)%n;

    set<int> idx;
    rep(i,k) idx.insert((start+i)%n);

    for(int i:idx) cout << " " << a[i];
    cout << "\n";
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
