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
    int n;
    cin >>n;

    vector<int> p(n);
    vector<int> pos(n+1);
    rep(i,n){
        cin >>p[i];
        pos[p[i]] = i;
    }

    set<int> s;
    const int L = -1, R = n;
    s.insert(L);
    s.insert(R);
    rep(i,n) s.insert(i);

    ll ans = 0;
    for(int i=1; i<=n; ++i){
        auto itr = s.lower_bound(pos[i]);
        --itr;
        int l = *itr;
        int r = *s.upper_bound(pos[i]);

        ll ct = 0;
        if(l != L){
            --itr;
            ll b = l-(*itr);
            ct += b*(r-pos[i]);
        }
        if(r != R){
            itr = s.upper_bound(pos[i]);
            ++itr;
            ll b = (*itr)-r;
            ct += b*(pos[i]-l);
        }

        ans += ct*i;
        s.erase(pos[i]);
    }
    cout << ans << "\n";
    return 0;
}
