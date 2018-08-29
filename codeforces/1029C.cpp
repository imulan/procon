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
    scanf(" %d", &n);
    vector<int> l(n),r(n);
    rep(i,n) scanf(" %d %d", &l[i], &r[i]);

    multiset<int> L,R;
    rep(i,n){
        L.insert(l[i]);
        R.insert(r[i]);
    }

    int ans = 0;
    rep(i,n){
        L.erase(L.find(l[i]));
        R.erase(R.find(r[i]));

        int mx = *R.begin();
        int mn = *L.rbegin();
        ans = max(ans, mx-mn);

        L.insert(l[i]);
        R.insert(r[i]);
    }
    printf("%d\n", ans);
    return 0;
}
