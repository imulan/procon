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

bool pal(const string &s)
{
    int n = s.size();
    rep(i,n)if(s[i]!=s[n-1-i]) return false;
    return true;
}

int calc(const string &s)
{
    int n = s.size();
    int r = 1;
    rep(i,n)
    {
        for(int j=1; j<=n-i; ++j)
        {
            string t = s.substr(i,j);
            if(pal(t)) r = max(r,j);
        }
    }

    return r;
}

string b(int n)
{
    int M = n;

    rep(mask,1<<n)
    {
        string s = "";
        rep(i,n)
        {
            if(mask>>i&1) s+='b';
            else s+='a';
        }

        M = min(M,calc(s));
    }

    string ret = "";
    rep(mask,1<<n)
    {
        string s = "";
        rep(i,n)
        {
            if(mask>>i&1) s+='a';
            else s+='b';
        }
        reverse(all(s));

        if(calc(s) == M) ret = s;
    }
    return ret;
}

void solve()
{
    int n,a;
    scanf(" %d %d", &n, &a);

    if(a==1)
    {
        printf("%d ", n);
        rep(i,n) printf("%c", 'a');
        printf("\n");
    }
    else if(a==2)
    {
        string s = "";
        int ans = 4;
        if(n<13)
        {
            s = b(n);
            ans = calc(s);
        }
        else
        {
            string t = "aababb";
            rep(i,n) s += t[i%6];
        }

        cout << ans << " " << s << endl;
    }
    else
    {
        printf("1 ");
        rep(i,n) printf("%c", 'a'+(i%a));
        printf("\n");
    }
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
