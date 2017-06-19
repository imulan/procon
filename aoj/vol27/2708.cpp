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

bool dfs(string s)
{
    if(s=="ABC") return true;

    int S = s.size();

    bool ret = false;
    bool ng[3]={};

    int idx = 0;
    while(idx<S)
    {
        if(idx<S-2 && s[idx]=='A' && s[idx+1]=='B' && s[idx+2]=='C') idx+=3;
        else ng[s[idx++]-'A'] = true;
    }

    rep(i,3)if(!ng[i])
    {
        string t = "";
        idx = 0;
        while(idx<S)
        {
            if(idx<S-2 && s[idx]=='A' && s[idx+1]=='B' && s[idx+2]=='C')
            {
                t += 'A'+i;
                idx+=3;
            }
            else
            {
                t += s[idx];
                ++idx;
            }
        }
        if(t!=s) ret |= dfs(t);
    }

    return ret;
}

int main()
{
    string s;
    cin >>s;
    cout << (dfs(s)?"Yes":"No") << endl;
    return 0;
}
