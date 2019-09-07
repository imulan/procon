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
    scanf(" %d %d", &n, &k);

    map<int,vector<int>> m;
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        m[a[i]].pb(i);
    }

    int idx = 0;
    vector<int> ans(n);
    for(const auto &p:m){
        vector<int> v = p.se;
        if(v.size() > k){
            printf("NO\n");
            return 0;
        }

        for(int i:v){
            ans[i] = idx;
            (idx += 1) %= k;
        }
    }

    printf("YES\n");
    rep(i,n) printf("%d%c", ans[i]+1, " \n"[i==n-1]);
    return 0;
}
