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
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<bool> s(n);
    rep(i,n-1)if(!s[i]){
        int mn = 191919;
        int idx = -1;
        for(int j=i; j<n; ++j){
            if(a[j] < mn){
                mn = a[j];
                idx = j;
            }
        }

        for(int j=idx; j>i; --j){
            s[j-1] = true;
            swap(a[j], a[j-1]);
        }
    }

    rep(i,n) cout << a[i] << " \n"[i==n-1];
}

int main(){
    int q;
    cin >>q;
    rep(i,q) solve();
    return 0;
}
