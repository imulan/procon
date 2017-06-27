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
    int a,b,l,r;
    cin >>a >>b >>l >>r;

    --l;
    --r;

    string x="",y="";
    rep(i,a) x+='a'+i;

    rep(i,b) x+=x[a-1];

    bool use[30]={};
    rep(i,a) use[x[x.size()-1-i]-'a']=true;

    int ct = 0;
    rep(i,30)
    {
        if(!use[i])
        {
            y+='a'+i;
            ++ct;
        }

        if(ct==a) break;
    }
    rep(i,b) y+=y[a-1];

    string s = x+y;
    // dbg(s);

    int n = 2*(a+b);
    int ap[30]={};
    if(n<=r-l+1)
    {
        rep(i,n) ap[s[i]-'a']=1;
    }
    else
    {
        for(int i=l; i<=r; ++i) ap[s[i%n]-'a']=1;
    }

    int ans = 0;
    rep(i,30) ans += ap[i];
    cout << ans << endl;
    return 0;
}
