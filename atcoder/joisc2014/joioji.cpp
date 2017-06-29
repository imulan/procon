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

using pi = pair<int,int>;
using P = pair<pi,int>;

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    string s;
    cin >>n >>s;

    multiset<P> m;
    int J=0, O=0, I=0;
    rep(i,n)
    {
        if(s[i]=='J') ++J;
        else if(s[i]=='O') ++O;
        else ++I;

        m.insert({pi(J-O,J-I),-J});
    }

    int ans = 0;
    J=O=I=0;
    rep(i,n)
    {
        P q(pi(J-O,J-I),-364364364);

        auto itr = m.lower_bound(q);
        if(itr!=m.end())
        {
            if((*itr).fi == pi(J-O,J-I)) ans = max(ans, (-(*itr).se-J)*3);
        }

        if(s[i]=='J') ++J;
        else if(s[i]=='O') ++O;
        else ++I;

        itr = m.find(P(pi(J-O,J-I),-J));
        m.erase(itr);
    }

    cout << ans << endl;
    return 0;
}
