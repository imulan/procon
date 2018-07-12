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

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    map<ll,vector<int>> v2id;
    rep(i,n) v2id[a[i]].pb(i);

    vector<ll> p;
    rep(i,31) p.pb(1<<i);

    int ans = 0;
    rep(i,n){
        int add = 1;
        for(int t:p){
            int v = t-a[i];
            if(v<=0) continue;

            if(v2id.count(v)){
                if(v2id[v].size()==1){
                    if(v2id[v][0] != i) add = 0;
                }
                else if(v2id[v].size()>1) add = 0;
            }
        }

        ans += add;
    }
    cout << ans << endl;
    return 0;
}
