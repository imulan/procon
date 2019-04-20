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

const int N = 10000000;
ll T[N]={};

int calcdist(int from, int to, int s){
    if(to<from) to += s;
    return to-from;
}

int main(){
    int n,s,t;
    cin >>n >>s >>t;

    vector<int> k(n);
    rep(i,n) cin >>k[i];

    vector<int> pos(k);
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    for(int idx:pos){
        multiset<int> b;
        rep(i,n) b.insert(k[i]);

        ll ans = 0;
        int now = idx;
        while(!b.empty()){
            auto itr = b.lower_bound(now);
            if(itr == b.end()) itr = b.begin();

            int d = calcdist(now, *itr, s);
            ans += d+t;

            now = *itr;
            (now += t) %= s;

            b.erase(itr);
        }

        T[idx] = ans;
    }

    int start = pos[0];
    // dbg(start);
    rep(i,s){
        if(T[(start-i-1+2*s)%s] == 0) T[(start-i-1+2*s)%s] = T[(start-i+s)%s]+1;
    }

    ll mn = LLONG_MAX, mx = 0;
    ll sum = 0;
    rep(i,s){
        // dbg(T[i]);
        mn = min(mn, T[i]);
        mx = max(mx, T[i]);
        sum += T[i];
    }

    cout << mn << endl;
    cout << mx << endl;
    ll g = __gcd(sum,(ll)s);
    cout << sum/g << "/" << s/g << endl;
    return 0;
}
