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

const int N = 200020;
ll sa[N]={};

int main(){
    int n;
    cin >>n;
    vector<int> a(n+1);
    rep(i,n) cin >>a[i+1];
    int s,f;
    cin >>s >>f;

    int d = f-s;

    rep(i,n) sa[i+1] = sa[i]+a[i+1];
    rep(i,n) sa[i+1+n] = sa[i+n]+a[i+1];

    ll p = 0;
    int ans = 0;
    for(int i=1; i<=n; ++i){
        ll tmp = sa[i+d-1] - sa[i-1];
        // dbg(tmp);

        int tans = s-i+1;
        while(tans<=0) tans += n;

        if(p < tmp){
            p = tmp;
            ans = tans;
        }
        else if(p == tmp) ans = min(ans,tans);
    }

    cout << ans << endl;
    return 0;
}
