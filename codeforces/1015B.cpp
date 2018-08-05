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
    string s,t;
    cin >>n >>s >>t;

    const int A = 26;
    vector<int> cs(A), ct(A);
    rep(i,n){
        ++cs[s[i]-'a'];
        ++ct[t[i]-'a'];
    }

    if(cs != ct){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    rep(i,n){
        int idx = i;
        while(idx<n && t[i]!=s[idx]) ++idx;

        for(int j=idx; j>i; --j){
            swap(s[j], s[j-1]);
            ans.pb(j);
        }
    }

    int sz = ans.size();
    cout << sz << endl;
    rep(i,sz) cout << ans[i] << " \n"[i==sz-1];
    return 0;
}
