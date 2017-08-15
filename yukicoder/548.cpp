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

int main()
{
    string s;
    cin >>s;

    int ct[26]={};
    rep(i,s.size()) ++ct[s[i]-'a'];

    vector<char> ans;
    rep(i,13)
    {
        ++ct[i];
        bool ok = false;
        rep(j,13)
        {
            int t=0;
            rep(k,13)
            {
                if(j==k) t += (ct[k]==2);
                else t += (ct[k]==1);
            }
            if(t==13)
            {
                ok = true;
                break;
            }
        }

        if(ok) ans.pb('a'+i);
        --ct[i];
    }

    if(!ans.size()) printf("Impossible\n");
    else for(auto c:ans) printf("%c\n", c);
    return 0;
}
