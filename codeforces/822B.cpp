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

int main()
{
    int S,T;
    string s,t;
    cin >>S >>T >>s >>t;

    int k = S;
    vector<int> ans(k);
    iota(all(ans),0);
    // dbg(ans);

    rep(i,T-S+1)
    {
        vector<int> v;
        rep(j,S)if(s[j] != t[i+j]) v.pb(j);
        if(v.size()<k)
        {
            k = v.size();
            ans = v;
        }
    }

    cout << k << endl;
    rep(i,k)
    {
        if(i) cout << " ";
        cout << ans[i]+1;
    }
    cout << endl;
    return 0;
}
