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

string g(int n, int mask)
{
    string s(n,' ');
    rep(i,n)
    {
        if(mask>>i&1) s[i]='1';
        else s[i]='0';
    }
    return s;
}

bool p(string s)
{
    int S = s.size();
    rep(i,S)if(s[i]!=s[S-1-i]) return false;
    return true;
}

int ct(int n, int mask)
{
    string s = g(n,mask);
    set<string> ans;
    // dbg(s);
    rep(i,n)
    {
        for(int L=1; L<=n-i; ++L)
        {
            string t = s.substr(i,L);
            // dbg(t);
            if(p(s.substr(i,L))) ans.insert(t);
        }
    }
    return ans.size();
}

void test(int n)
{
    int m = n;
    rep(mask,1<<n) m = min(m,ct(n,mask));

    dbg(m);
    rep(mask,1<<n)
    {
        if(m == ct(n,mask)) cout << "can: "<<g(n,mask)<<endl;
    }
}

int main()
{
    int n;
    cin >>n;
    // test(n);

    string b = "110100";
    string ans(n,' ');
    int idx = 5;
    for(int i=n-1; i>=0; --i)
    {
        ans[i] = b[idx];
        idx = (idx+5)%6;
    }


    int x[10]={0,1,2,3,4,5,6,7,7};

    int num = 8;
    if(n<9) num = x[n];

    cout << num << endl;
    cout << ans << endl;
    return 0;
}
