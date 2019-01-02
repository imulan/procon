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

const ll INF = LLONG_MAX/3;

int main(){
    int h,w;
    cin >>h >>w;
    vector<ll> a(h),b(w);
    rep(i,h) cin >>a[i];
    rep(i,w) cin >>b[i];
    sort(all(a));
    sort(all(b));

    ll ans = 0;
    ll A=0, B=0;
    int ai=0, bi=0;
    while(ai<h && bi<w){
        ll av = INF, bv = INF;
        if(ai<h) av = a[ai];
        if(bi<w) bv = b[bi];

        if(av<=bv){
            ans += av*(w-B);
            ++A;
            ++ai;
        }
        else{
            ans += bv*(h-A);
            ++B;
            ++bi;
        }
    }
    cout << ans << endl;
    return 0;
}
