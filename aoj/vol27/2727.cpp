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

string s,t;
int S,T;

bool check(int a)
{
    bool ok = true;
    int idx = 0;
    for(int i=a; i<S; i+=2)
    {
        bool update = false;
        while(idx<T)
        {
            if(t[idx]==s[i])
            {
                ++idx;
                update = true;
                break;
            }
            ++idx;
        }
        if(!update)
        {
            ok=false;
            break;
        }
    }
    return ok;
}

string solve()
{
    cin >>s >>t;
    S = s.size();
    T = t.size();
    rep(i,2)if(check(i)) return "Yes";
    return "No";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
