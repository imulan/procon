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

using vi = vector<int>;

int solve()
{
    string s,t;
    cin >>s >>t;
    int S = s.size(), T = t.size();

    for(int i=min(S,T); i>0; --i)
    {
        set<vi> x;

        vi ct(26);
        rep(j,i) ++ct[s[j]-'a'];
        x.insert(ct);

        for(int j=i; j<S; ++j)
        {
            --ct[s[j-i]-'a'];
            ++ct[s[j]-'a'];
            x.insert(ct);
        }

        ct = vi(26);
        rep(j,i) ++ct[t[j]-'a'];
        if(x.count(ct)) return i;

        for(int j=i; j<T; ++j)
        {
            --ct[t[j-i]-'a'];
            ++ct[t[j]-'a'];
            if(x.count(ct)) return i;
        }
    }
    return 0;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
