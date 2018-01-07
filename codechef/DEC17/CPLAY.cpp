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

void solve(string s)
{
    int ra=5, rb=5;
    int a=0,b=0;
    rep(i,10)
    {
        if(i%2==0)
        {
            a+=(s[i]-'0');
            --ra;
        }
        else
        {
            b+=(s[i]-'0');
            --rb;
        }

        if(a>b+rb)
        {
            cout << "TEAM-A " << i+1 << '\n';
            return;
        }
        if(b>a+ra)
        {
            cout << "TEAM-B " << i+1 << '\n';
            return;
        }
    }

    // sudden death
    rep(i,5)
    {
        a += (s[10+2*i]-'0');
        b += (s[10+2*i+1]-'0');

        if(a!=b)
        {
            char c='A';
            if(b>a) c='B';
            cout << "TEAM-" << c << " " << 10+2*(i+1) << '\n';
            return;
        }
    }
    cout << "TIE" << '\n';
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    string s;
    while(cin >>s) solve(s);
    return 0;
}
