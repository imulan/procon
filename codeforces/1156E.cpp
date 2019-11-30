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

using pi = pair<int,int>;

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> p(n);
    rep(i,n) scanf(" %d", &p[i]);

    vector<int> pos(n+1);
    rep(i,n) pos[p[i]] = i;

    set<pi> s;
    s.insert({0,n-1});
    int ans = 0;
    for(int i=n; i>0; --i){
        auto itr = s.lower_bound({pos[i], n+1});
        --itr;

        pi seg = *itr;
        int l = seg.fi, r = seg.se;

        assert(l<=pos[i] && pos[i]<=r);

        pi range = {l, pos[i]-1};
        pi check = {pos[i]+1, r};
        if(pos[i]-l > r-pos[i]) swap(range,check);

        for(int j=range.fi; j<=range.se; ++j){
            int val = i - p[j];
            assert(val>0);
            if(check.fi<=pos[val] && pos[val]<=check.se) ++ans;
        }

        s.erase(itr);
        for(pi t:vector<pi>({{l,pos[i]-1},{pos[i]+1,r}})){
            if(t.fi<=t.se) s.insert(t);
        }
    }

    printf("%d\n", ans);
    return 0;
}
