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

int main(){
    int n,k;
    cin >>n >>k;
    vector<int> v(n);
    rep(i,n) cin >>v[i];

    int ans = 0;
    rep(i,n+1)for(int j=i; j<=n; ++j){
        int rem = k;
        vector<int> h;
        rep(x,i){
            h.pb(v[x]);
            --rem;
        }
        for(int x=j; x<n; ++x){
            h.pb(v[x]);
            --rem;
        }

        if(rem<0) continue;
        sort(all(h));

        int H = h.size();
        int idx = 0;
        while(idx<H && h[idx]<0 && rem>0){
            ++idx;
            --rem;
        }

        int s = 0;
        for(int x=idx; x<H; ++x) s += h[x];
        ans = max(ans, s);
    }

    cout << ans << endl;
    return 0;
}
