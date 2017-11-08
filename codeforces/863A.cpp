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

bool p(const string &s)
{
    int S = s.size();
    rep(i,S)if(s[i]!=s[S-1-i]) return false;
    return true;
}

bool solve(string s)
{
    rep(i,12)
    {
        if(p(s)) return true;
        s = "0"+s;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << (solve(s)?"YES":"NO") << endl;
    return 0;
}
