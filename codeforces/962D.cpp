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

    map<ll,priority_queue<int, vector<int>, greater<int>>> m;
    rep(i,n){
        ll a;
        cin >>a;
        m[a].push(i);
    }

    for(auto &t:m){
        while(t.se.size() >= 2){
            t.se.pop();
            int idx = t.se.top();
            t.se.pop();

            m[2*t.fi].push(idx);
        }
    }

    vector<pair<int,ll>> v;
    for(auto &t:m){
        assert(t.se.size()<=1);
        if(!t.se.empty()){
            int idx = t.se.top();
            v.pb({idx,t.fi});
        }
    }

    sort(all(v));
    int V = v.size();
    cout << V << "\n";
    rep(i,V) cout << v[i].se << " \n"[i==V-1];
    return 0;
}
