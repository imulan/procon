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

vector<int> top2(map<int,int> m){
    vector<pair<int,int>> v;
    for(const auto &p:m) v.pb({p.se,p.fi});

    sort(all(v));
    reverse(all(v));
    return vector<int>({v[0].se, v[1].se});
}

int main(){
    int n;
    cin >>n;

    map<int,int> m[2];
    rep(i,n){
        int v;
        cin >>v;
        ++m[i%2][v];
    }
    rep(i,2) m[i][-1] = 0;

    int ans = n;
    for(int i:top2(m[0]))for(int j:top2(m[1]))if(i!=j){
        ans = min(ans, n-m[0][i]-m[1][j]);
    }
    cout << ans << endl;
    return 0;
}
