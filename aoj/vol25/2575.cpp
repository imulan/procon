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

bool ana(string s)
{
    int ct[26]={};
    rep(i,s.size()) ++ct[s[i]-'A'];

    rep(i,26)
    {
        if(i+'A'=='A' || i+'A'=='N')
        {
            if(ct[i]!=2) return false;
        }
        else if(i+'A'=='I' || i+'A'=='D' || i+'A'=='U' || i+'A'=='Y')
        {
            if(ct[i]!=1) return false;
        }
        else
        {
            if(ct[i]!=0) return false;
        }
    }
    return true;
}

int main()
{
    string d;
    cin >>d;

    int D = d.size();
    int i = 0;
    string ans = "";
    while(i<D)
    {
        if(i+7<D && ana(d.substr(i,8)))
        {
            ans += "AIZUNYAN";
            i += 8;
        }
        else ans += d[i++];
    }

    cout << ans << endl;
    return 0;
}
