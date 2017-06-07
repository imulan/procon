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

const int A=26;

int main()
{
    ll f[21];
    f[0]=1;
    for(int i=1; i<=20; ++i) f[i]=f[i-1]*i;

    string s;
    cin >>s;

    int S = s.size();
    vector<int> ct(A);
    rep(i,S) ++ct[s[i]-'A'];

    ll ans = 1;
    rep(i,S)
    {
        rep(j,s[i]-'A')
        {
            if(ct[j] == 0) continue;
            vector<int> t(ct);
            --t[j];

            int r=0;
            rep(k,A) r+=t[k];
            ll add=f[r];

            rep(k,A) add/=f[t[k]];

            ans += add;
        }

        --ct[s[i]-'A'];
    }

    cout << ans << endl;
    return 0;
}
