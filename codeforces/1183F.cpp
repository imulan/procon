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

vector<int> divisor(int x){
    vector<int> ret;
    for(int i=1; i*i<=x; ++i){
        if(x%i==0){
            ret.pb(i);
            if(i != x/i) ret.pb(x/i);
        }
    }
    sort(all(ret));
    return ret;
}

void test(){
    ll s = 0;
    int mx = 0;
    for(int i=2; i<=200000; ++i){
        vector<int> d = divisor(i);
        int sz = d.size();
        s += sz;
        mx = max(mx, sz);
    }
    dbg(s); // s = 2472112
    dbg(mx); // mx = 160
}

int solver1(const vector<int> &a){
    int n = a.size();

    vector<vector<int>> d(n);
    rep(i,n) d[i] = divisor(a[i]);

    // 1 element
    int ans = a[n-1];

    set<int> s;
    rep(i,n){
        int vi = a[i];

        vector<int> removed;
        for(int x:d[i])if(s.count(x)){
            removed.pb(x);
            s.erase(x);
        }

        if(!s.empty()){
            int vj = *s.rbegin();
            // 2 elements
            ans = max(ans, vi+vj);

            int vj_idx = lower_bound(all(a), vj)-a.begin();
            for(int x:d[vj_idx])if(s.count(x)){
                removed.pb(x);
                s.erase(x);
            }
            if(!s.empty()){
                int vk = *s.rbegin();
                // 3 elements
                ans = max(ans, vi+vj+vk);
            }
        }

        for(int y:removed) s.insert(y);
        s.insert(vi);
    }

    return ans;
}

int solver2(const vector<int> &a){
    int n = a.size();

    set<int> s;
    for(int i:a) s.insert(i);

    int ans = 0;

    int X = a[n-1];
    if(X%2==0 && X%3==0 && X%5==0){
        if(s.count(X/2) && s.count(X/3) && s.count(X/5)){
            ans = max(ans, X/2+X/3+X/5);
        }
    }

    int t = 0;
    rep(i,3){
        if(!s.empty()){
            int mx = *s.rbegin();
            for(int j:divisor(mx)){
                if(s.count(j)) s.erase(j);
            }
            t += mx;
        }
    }
    ans = max(ans, t);
    return ans;
}

int solve(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    return solver2(a);
}

int main(){
    // test();

    int q;
    scanf(" %d", &q);
    while(q--) printf("%d\n", solve());
    return 0;
}
