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
    string s;
    int x,y;
    cin >>s >>x >>y;

    int n = s.size();
    int a=0,b=0;
    rep(i,n)
    {
        if(s[i]=='a') ++a;
        else ++b;
    }

    string ans = "";
    string add = "ab";
    if(a<b)
    {
        add = "ab";
        while(1)
        {
            if(b-y<=a)
            {
                rep(i,b-a) ans += 'b';
                b -= b-a;
                break;
            }
            else
            {
                rep(i,y) ans += 'b';
                b -= y;

                if(a>0)
                {
                    ans += 'a';
                    --a;
                }
                else ans += '*';
            }
        }
    }
    else if(a>b)
    {
        add = "ba";
        while(1)
        {
            if(a-x<=b)
            {
                rep(i,a-b) ans += 'a';
                a -= a-b;
                break;
            }
            else
            {
                rep(i,x) ans += 'a';
                a -= x;

                if(b>0)
                {
                    ans += 'b';
                    --b;
                }
                else ans += '*';
            }
        }

    }

    // dbg(ans);
    // dbg(a);dbg(b);
    rep(i,a) ans += add;
    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
