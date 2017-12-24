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

string solve()
{
    int n,p;
    cin >>n >>p;

    int c=0,h=0;
    rep(i,n)
    {
        int a;
        cin >>a;

        if(a>=p/2) ++c;
        if(a<=p/10) ++h;
    }

    string ans = "no";
    if(c==1 && h==2) ans = "yes";
    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
