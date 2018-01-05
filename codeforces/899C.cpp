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
    int n;
    cin >>n;

    ll s=0;
    rep(i,n) s+=i+1;

    ll t = s/2;
    vector<int> ans;
    for(int i=n; i>0; --i){
        if(t-i>=0){
            t -= i;
            ans.pb(i);
        }
    }

    t = s/2;
    printf("%lld\n", abs(t-(s-t)));
    printf("%d",ans.size());
    for(int i:ans) printf(" %d",i);
    printf("\n");
    return 0;
}

// 1,2,3,4,5,6,7 = 10+12+6=28
// 14=7+6+1

// 1,2,3,4,5 = 15
// 7 = 5+2