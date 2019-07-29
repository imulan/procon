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
    int n,k;
    cin >>n >>k;

    vector<int> p,m;
    rep(i,n){
        int x;
        cin >>x;

        if(x>=0) p.pb(x);
        else m.pb(-x);
    }
    sort(all(p));
    sort(all(m));
    int P = p.size(), M = m.size();

    int ans = INT_MAX;
    rep(i,k+1){
        int j = k-i;
        if(i>P ||j>M) continue;

        int pd = 0;
        if(i) pd = p[i-1];

        int md = 0;
        if(j) md = m[j-1];

        ans = min(ans, 2*min(pd,md)+max(pd,md));
    }
    cout << ans << endl;
    return 0;
}
