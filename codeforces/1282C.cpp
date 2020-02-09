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

int solve(){
    int n,t;
    ll x[2];
    scanf(" %d %d %lld %lld", &n, &t, &x[0], &x[1]);

    vector<int> d(n),ct(2);
    rep(i,n){
        scanf(" %d", &d[i]);
        ++ct[d[i]];
    }

    vector<int> ut;
    map<int,vector<int>> mandatory;
    rep(i,n){
        int a;
        scanf(" %d", &a);
        mandatory[a].pb(i);
        ut.pb(a);
        if(a-1 >= 0) ut.pb(a-1);
    }
    ut.pb(0);
    ut.pb(t);
    sort(all(ut));
    ut.erase(unique(all(ut)), ut.end());

    int ans = 0;
    vector<int> must(2);
    for(int i:ut){
        for(int j:mandatory[i]) ++must[d[j]];

        ll need = 0;
        rep(j,2) need += x[j]*must[j];
        if(need > i) continue;

        int tmp = must[0]+must[1];
        int rem = i-need;
        rep(j,2){
            int num = ct[j]-must[j];
            int mx = rem/x[j];
            num = min(num,mx);

            rem -= num*x[j];
            tmp += num;
        }
        ans = max(ans,tmp);
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--) printf("%d\n", solve());
    return 0;
}
