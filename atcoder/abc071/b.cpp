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

string solve(string s)
{
    rep(i,26)
    {
        char c = 'a'+i;
        bool found = false;
        rep(j,s.size())
        {
            if(s[j]==c)
            {
                found = true;
                break;
            }
        }
        if(!found) return string(1,c);
    }
    return "None";
}

int main()
{
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
