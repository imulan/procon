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

int f(vector<string> s, string t)
{
    map<char,int> c;
    c['R'] = 5;
    c['G'] = 3;

    int n=s.size(), m=s[0].size();
    int ret = 0;
    rep(i,n)rep(j,m)if(t[(i+j)%2] != s[i][j]) ret += c[s[i][j]];
    return ret;
}

int solve()
{
    int n,m;
    cin >>n >>m;
    vector<string> s(n);
    rep(i,n) cin >>s[i];
    return min(f(s,"RG"),f(s,"GR"));
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
