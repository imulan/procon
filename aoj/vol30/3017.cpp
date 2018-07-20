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
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    auto itr = unique(all(a));
    a.resize(distance(a.begin(),itr));
    n = a.size();

    vector<int> d(n-1);
    rep(i,n-1) d[i] = (a[i]<a[i+1]);

    int ans = 1;
    int s = 0;
    while(s<n-1){
        int idx = s;
        while(idx<n-1 && d[s]==d[idx]) ++idx;
        ans = max(ans, idx-s+1);
        s = idx;
    }
    cout << ans << endl;
    return 0;
}
