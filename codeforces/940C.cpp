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
    int n,k;
    string s;
    cin >>n >>k >>s;

    vector<char> x;
    rep(i,n) x.pb(s[i]);
    sort(all(x));
    x.erase(unique(all(x)),x.end());

    string ans = "";
    if(n<k){
        ans = s;
        rep(i,k-n) ans += x[0];
    }
    else{
        ans.resize(k);
        int idx = k-1;
        while(idx>=0 && s[idx]==x.back()) --idx;

        rep(i,idx) ans[i]=s[i];
        ans[idx] = *upper_bound(all(x),s[idx]);
        for(int i=idx+1; i<k; ++i) ans[i] = x[0];
    }
    cout << ans << endl;
    return 0;
}
