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
    string s;
    cin >>s;

    ll v = atoll(s.c_str());
    ll ten = 1;
    rep(i,s.size()) ten*=10;

    vector<int> p(10);
    iota(all(p),0);

    string ans;
    ll ansd = -1;
    do {
        string t = "";
        rep(i,s.size()) t += '0'+p[i];
        ll u  = atoll(t.c_str());
        ll d = min(abs(v-u),ten-abs(v-u));
        if(ansd<d || (ansd==d && atoll(ans.c_str())>atoll(t.c_str())))
        {
            ansd = d;
            ans = t;
        }

    } while(next_permutation(all(p)));

    cout << ans << endl;
    return 0;
}
