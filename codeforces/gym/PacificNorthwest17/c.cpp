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

const int N = 1000010;

int main(){
    ll a,b;
    cin >>a >>b;

    ll n = b-a+1;
    vector<ll> x(n);
    rep(i,n) x[i]=a+i;

    unsigned long long ans = 0;
    for(int i=1; i<N; ++i){
        int idx = a%i;
        if(idx>0) idx = i-idx;

        // printf(" i %d\n", i);
        for(int j=idx; j<n; j+=i){
            // dbg(a+j);
            if(i<=x[j]/i){
                ans += i;
                if(i != x[j]/i) ans += x[j]/i;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
