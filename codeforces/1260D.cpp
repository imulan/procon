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
    int m,n,k,t;
    scanf(" %d %d %d %d", &m, &n, &k, &t);

    vector<int> a(m);
    rep(i,m) scanf(" %d", &a[i]);
    sort(all(a), greater<int>());

    vector<int> l(k),r(k),d(k);
    rep(i,k) scanf(" %d %d %d", &l[i], &r[i], &d[i]);

    auto check = [&](int x){
        int A = a[x-1];

        vector<int> s(n+2);
        rep(i,k)if(A < d[i]){
            ++s[l[i]];
            --s[r[i]+1];
        }

        rep(i,n+1) s[i+1] += s[i];

        int z = 0;
        rep(i,n+1){
            ++z;
            if(s[i]) z += 2;
        }
        return z<=t;
    };

    int ok=0, ng=m+1;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%d\n", ok);
    return 0;
}
