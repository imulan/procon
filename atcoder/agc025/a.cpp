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

int d(int x){
    int ret = 0;
    while(x){
        ret += x%10;
        x/=10;
    }
    return ret;
}

int main(){
    int n;
    cin >>n;

    int ans = 1234567;
    for(int i=1; i<n; ++i){
        int j=n-i;
        ans = min(ans, d(i)+d(j));
    }
    cout << ans << endl;
    return 0;
}
