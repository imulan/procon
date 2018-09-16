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

using pi = pair<int,int>;

void solve(){
    int n;
    cin >>n;
    vector<int> a(n-1),b(n-1);
    rep(i,n-1){
        cin >>a[i] >>b[i];
        --a[i];
        --b[i];
    }

    vector<int> ct(n);
    vector<int> amari;

    rep(i,n-1){
        if(b[i] != n-1){
            cout << "NO" << endl;
            return;
        }

        ++ct[a[i]];
    }

    rep(i,n-1)if(ct[i]==0) amari.pb(i);

    vector<vector<int>> v(n);
    int idx = 0;
    for(int i:amari){
        while(idx<i || (idx<n && ct[idx]<=1)) ++idx;
        if(idx==n || ct[idx]<=1){
            cout << "NO" << endl;
            return;
        }

        v[idx].pb(i);
        --ct[idx];
    }

    vector<pi> ans;
    rep(i,n)if(ct[i]){
        int pre = n-1;
        for(int c:v[i]){
            ans.pb({pre,c});
            pre = c;
        }
        ans.pb({pre,i});
    }

    cout << "YES" << endl;
    for(const auto &p:ans) cout << p.fi+1 << " " << p.se+1 << endl;
}

int main(){
    solve();
    return 0;
}
