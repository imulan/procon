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

const int LIM = 1e9;

ll solve(){
    set<int> sq;
    rep(i,LIM){
        if((i-1)*(i-1)>LIM) break;
        sq.insert(i*i);
    }

    int n;
    cin >>n;

    vector<int> s,ns;
    rep(i,n){
        int a;
        cin >>a;
        if(sq.count(a)) s.pb(a);
        else ns.pb(a);
    }

    ll ret = 0;
    int S = s.size(), NS = ns.size();
    vector<int> cost;
    if(S >= NS){
        for(int i:s){
            int add = 1;
            if(i==0) add = 2;
            cost.pb(add);
        }
    }
    else{
        for(int i:ns){
            int add = LIM;

            auto itr = sq.upper_bound(i);
            add = min(add, abs(*itr - i));
            --itr;
            add = min(add, abs(*itr - i));

            cost.pb(add);
        }
    }

    sort(all(cost));
    rep(i, n/2-min(S,NS)) ret += cost[i];
    return ret;
}

int main(){

    cout << solve() << endl;
    return 0;
}
