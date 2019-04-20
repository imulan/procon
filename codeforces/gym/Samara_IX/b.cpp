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

int main(){
    int n;
    cin >>n;

    vector<int> p(n);
    vector<int> fp;
    rep(i,n){
        cin >>p[i];
        --p[i];
        if(p[i]==i) fp.pb(i);
    }

    vector<pi> ans;

    int F = fp.size();
    for(int i=0; i+1<F; i+=2){
        int a = fp[i], b = fp[i+1];
        ans.pb({a,b});
        swap(p[a],p[b]);
    }

    if(F%2 == 1){
        int idx = fp.back();
        rep(i,n)if(idx != i){
            if(p[idx]!=i && p[i]!=idx){
                ans.pb({i,idx});
                swap(p[i],p[idx]);
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for(pi a:ans) cout << a.fi+1 << " " << a.se+1 << "\n";
    return 0;
}
