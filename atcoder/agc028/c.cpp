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

using pi = pair<int,int>;
using P = pair<int,pi>;

int main(){
    int n;
    cin >>n;

    vector<vector<int>> w(n, vector<int>(2));
    rep(i,n)rep(j,2) cin >>w[i][j];

    vector<P> v;
    set<pi> r[2];
    rep(i,n)rep(j,2){
        v.pb({w[i][j],{i,j}});
        r[j].insert({w[i][j],i});
    }

    sort(all(v));

    vector<int> nx(n,-1), pv(n,-1);
    for(const auto &p:v){
        int idx = p.se.fi;
        int t = p.se.se;

        if( !r[t].count({w[idx][t], idx}) ) continue;

        auto itr =


    }

    return 0;
}
