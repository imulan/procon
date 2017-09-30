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

char m(char c)
{
    if(c=='(') return')';
    if(c==')') return'(';
    if(c=='{') return'}';
    if(c=='}') return'{';
    if(c=='[') return']';
    if(c==']') return'[';
    assert(false);
}

int main()
{
    string a;
    cin >>a;

    int idx = 0;
    while(a[idx]!='i') ++idx;

    string s = a.substr(0,idx), t = a.substr(idx+3);
    if(s.size()>t.size()) swap(s,t);
    reverse(all(t));

    int S = s.size() , T = t.size();
    int ans = 3;
    for(int mask=1; mask<(1<<S); ++mask)
    {
        string x = "";
        rep(i,S)if(mask>>i&1) x += s[i];

        int X = x.size();
        idx = 0;
        rep(i,T)if(idx<X && x[idx]==m(t[i])) ++idx;
        if(idx==X) ans = max(ans,3+2*X);
    }

    cout << ans << endl;
    return 0;
}
