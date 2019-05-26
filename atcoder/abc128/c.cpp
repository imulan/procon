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
    int n,m;
    cin >>n >>m;

    vector<vector<bool>> l(m);
    rep(i,m){
        vector<bool> b(n);
        int k;
        cin >>k;
        rep(j,k){
            int s;
            cin >>s;
            --s;
            b[s] = true;
        }
        l[i] = b;
    }

    vector<int> p(m);
    rep(i,m) cin >>p[i];

    int ans = 0;
    rep(mask,1<<n){
        vector<int> ct(m);
        rep(i,n)if(mask>>i&1){
            rep(j,m)if(l[j][i]) (ct[j]+=1)%=2;
        }
        ans += (ct == p);
    }
    cout << ans << endl;
    return 0;
}
