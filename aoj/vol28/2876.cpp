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
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    map<int,int> f,b;
    set<int> diff;

    vector<int> ans;
    rep(i,n){
        ++f[a[i]];
        ++b[a[n-1-i]];

        for(int v:{a[i], a[n-1-i]}){
            if(f[v] == b[v]) diff.erase(v);
            else diff.insert(v);
        }

        if(diff.empty()) ans.pb(i+1);
    }

    int A = ans.size();
    rep(i,A) cout << ans[i] << " \n"[i==A-1];
    return 0;
}
