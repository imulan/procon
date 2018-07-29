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

    set<int> s;
    vector<int> ans;
    for(int i=n-1; i>=0; --i){
        if(!s.count(a[i])){
            ans.pb(a[i]);
            s.insert(a[i]);
        }
    }

    reverse(all(ans));
    int A = ans.size();
    cout << A << endl;
    rep(i,A) cout << ans[i] << " \n"[i==A-1];
    return 0;
}
