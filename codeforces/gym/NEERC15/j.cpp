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

inline int query(const vector<int> &v){
    rep(i,v.size()) cout << v[i];
    cout << endl;

    int res;
    cin >>res;
    return res;
}

int main(){
    int n;
    cin >>n;

    random_device rnd;
    mt19937 mt(rnd());

    vector<int> v(n);
    bool found = false;
    rep(loop,499){
        rep(i,n) v[i] = mt()%2;

        int res = query(v);
        if(res == n) return 0;
        if(res == n/2){
            found = true;
            break;
        }
    }
    assert(found);

    vector<int> q(n,-1);
    for(int i=1; i<n; ++i){
        vector<int> tmp = v;
        tmp[0] = !tmp[0];
        tmp[i] = !tmp[i];

        int res = query(tmp);
        if(res == n) return 0;
        q[i] = res;
    }

    vector<int> ans(n,-1);

    // 正しいと仮定した場合
    ans[0] = v[0];
    for(int i=1; i<n; ++i){
        if(q[i] == n/2) ans[i] = !v[i];
        else ans[i] = v[i];
    }
    if(query(ans) == n) return 0;

    // ちがうと仮定した場合
    ans[0] = !v[0];
    for(int i=1; i<n; ++i){
        if(q[i] == n/2) ans[i] = v[i];
        else ans[i] = !v[i];
    }
    if(query(ans) == n) return 0;

    return 0;
}
