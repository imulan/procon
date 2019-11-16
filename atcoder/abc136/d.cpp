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
    string s;
    cin >>s;
    int n = s.size();

    vector<int> ans(n);
    int x=0;
    while(x<n){
        int r=x;
        while(s[r]=='R') ++r;
        int lidx = r;

        int l=r;
        while(l<n && s[l]=='L') ++l;

        int m = 0;
        for(int i=lidx-1; i>=x; --i){
            ++ans[lidx-1+m];
            m = !m;
        }
        m = 1;
        for(int i=lidx; i<l; ++i){
            ++ans[lidx-1+m];
            m = !m;
        }

        x=l;
    }

    rep(i,n) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
