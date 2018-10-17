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
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    if(m >= n){
        printf("%d\n",n);
        return 0;
    }

    // m<n
    auto check = [&](int num){
        int start = n-num;
        int rem = m, cap = k;
        for(int i=start; i<n; ++i){
            if(cap < a[i]){
                --rem;
                cap = k;
            }

            if(rem<=0) return false;
            cap -= a[i];
        }
        return true;
    };

    int ok=m, ng=n+1;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%d\n", ok);
    return 0;
}
