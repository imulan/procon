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

int Q(int n)
{
    if(n<=6) return n+1;
    return n-5;
}

int calcCD(string s)
{
    int r = 0;
    for(int i=1; i<=11; ++i) (r+=(s[i]-'0')*Q(i))%=11;

    if(r<=1) return 0;
    return 11 - r;
}

int main()
{
    string s;
    cin >>s;
    reverse(all(s));

    int idx = s.find('?');

    vector<int> ans;
    rep(i,10)
    {
        s[idx] = '0'+i;
        if(calcCD(s) == s[0]-'0') ans.pb(i);
    }

    if(ans.size()==1) cout << ans[0] << endl;
    else cout << "MULTIPLE" << endl;
    return 0;
}
