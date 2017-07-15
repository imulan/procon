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

bool ok(int v)
{
    string s = to_string(v);
    rep(i,s.size())if(s[i]!=s[0]+i) return false;
    return true;
}

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans = -1;
    rep(i,n)rep(j,i)
    {
        int v = a[i]*a[j];
        if(ok(v)) ans = max(ans,v);
    }

    cout << ans << endl;
    return 0;
}
