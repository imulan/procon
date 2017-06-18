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

bool check(string s, char c)
{
    rep(i,s.size())if(s[i]!=c) return false;
    return true;
}

int main()
{
    string s;
    cin >>s;
    int S = s.size();

    bool a[26]={};
    rep(i,S) a[s[i]-'a']=true;

    int ans = 1010;
    rep(alp,26)
    {
        if(!a[alp]) continue;

        char c = 'a'+alp;
        int ct = 0;
        string p=s, now;
        while(1)
        {
            if(check(p,c)) break;

            now = "";
            rep(i,(int)p.size()-1)
            {
                if(p[i]==c || p[i+1]==c) now+=c;
                else now+=p[i];
            }
            ++ct;
            p = now;
        }

        ans = min(ans,ct);
    }

    cout << ans << endl;
    return 0;
}
