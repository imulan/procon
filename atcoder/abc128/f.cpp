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

void test(){
    int n;
    cin >>n;
    auto IN = [&](int x){
        return 0<=x && x<n;
    };

    for(int sub=1; sub<n; ++sub){
        for(int a=1; a<n; ++a){
            int b = a-sub;
            if(b <= 0) continue;

            vector<bool> used(n);
            int p = 0;
            bool f = true;
            bool ok = true;
            while(p!=n-1){
                if(!IN(p) || used[p]){
                    ok = false;
                    break;
                }
                used[p] = true;
                if(f) p += a;
                else p -= b;
                f = !f;
            }

            if(ok){
                printf(" ab %d %d:", a, b);
                used[p] = true;
                rep(i,n)if(used[i]) printf(" %d", i);
                printf("\n");
            }
        }
    }
}

int main(){
    // test();

    int n;
    cin >>n;
    vector<ll> s(n);
    rep(i,n) cin >>s[i];

    auto IN = [&](int x){
        return 0<=x && x<n;
    };

    ll ans = 0;
    for(int w=1; w<n; ++w){
        int a = n-1, b = a-w;
        int l=0,r=n-1;
        ll t=0;
        unordered_set<int> vis;
        while(b>0 && l!=r && IN(l) && IN(r) && !vis.count(l) && !vis.count(r)){
            t += s[l];
            t += s[r];
            ans = max(ans, t);
            vis.insert(l);
            vis.insert(r);

            l += w;
            r -= w;
            b -= w;
        }
    }
    cout << ans << endl;
    return 0;
}
