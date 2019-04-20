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

vector<int> solve(){
    vector<int> NG(1,-1);

    int n,w;
    cin >>n >>w;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> ans(n);
    rep(i,n) ans[i]=(a[i]+1)/2;

    int s = 0;
    rep(i,n) s+=ans[i];
    if(s>w) return NG;

    w -= s;

    vector<pi> v;
    rep(i,n) v.pb({-a[i],i});
    sort(all(v));

    rep(i,n){
        int id = v[i].se;

        int c = a[id] - ans[id];
        if(w>c){
            ans[id] += c;
            w -= c;
        }
        else{
            ans[id] += w;
            w = 0;
        }
    }

    return ans;
}

int main(){
    vector<int> ans = solve();
    int A = ans.size();
    rep(i,A) cout << ans[i] << " \n"[i==A-1];
    return 0;
}
