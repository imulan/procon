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
    int n,k;
    cin >>n >>k;

    int idx = -1;
    rep(i,n){
        int a;
        cin >>a;
        if(a==1) idx = i;
    }

    int w = k-1;
    int ans = n;
    rep(loop,2){
        int l=idx;
        int t = (l+w-1)/w;

        if(l%w != 0) l += (w-l%w);
        l = min(l,n-1);

        int r = n-1-l;
        t += (r+w-1)/w;

        ans = min(ans,t);
        idx = n-1-idx;
    }
    cout << ans << endl;
    return 0;
}
