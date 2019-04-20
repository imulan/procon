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

void solve()
{
    string s;
    cin >>s;
    int n = s.size();

    char f = '?';
    int st = -1;
    rep(i,n)
    {
        if(s[i]!='.')
        {
            if(f==s[i])
            {
                int d = i-st+1;
                for(int j=st; j<i; ++j) s[j]=f;
            }
            f = s[i];
            st = i;
        }
    }

    int ct[2]={};
    rep(i,n)if(s[i]!='.') ++ct[s[i]-'A'];
    printf("%d %d\n", ct[0],ct[1]);
}

int main()
{
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
