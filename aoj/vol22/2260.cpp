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
    if(c=='i' || c=='w') return c;
    if(c=='(') return ')';
    if(c==')') return '(';
}

int main()
{
    string s;
    cin >>s;

    int S = s.size();
    int ans = 0;

    rep(i,S)
    {
        char f = m(s[i]);
        if(i == S-1-i)
        {
            if(s[i]!='i' && s[i]!='w')
            {
                s[i] = 'i';
                ++ans;
            }
        }
        else
        {
            if(s[S-1-i] != f)
            {
                s[S-1-i]=f;
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
