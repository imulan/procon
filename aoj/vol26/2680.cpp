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

const string NG = "invalid";

// 数字の形式として妥当か
bool num(string s)
{
    bool ret = true;
    rep(i,s.size())if(s[i]<'0' || '9'<s[i]) ret = false;
    if(s[0]=='0') ret = (s=="0");
    return ret;
}

string MAX(string a, string b)
{
    if(a==NG) return b;
    int A = a.size(), B = b.size();
    if(A>B) return a;
    if(A<B) return b;
    return (a<b?b:a);
}

map<string,string> dp;
string E(string s)
{
    int S = s.size();
    if(S==0) return NG;
    if(dp.count(s)) return dp[s];

    string ret = NG;
    if(s[0]=='L' || s[0]=='R')
    {
        if(S<6) return NG;
        if(!(s[1]=='('||s[1]=='?')) return NG;
        if(!(s[S-1]==')'||s[S-1]=='?')) return NG;

        string y = s.substr(2,S-3);
        int Y = y.size();
        for(int i=1; i<Y-1; ++i)
        {
            if(y[i]=='?' || y[i]==',')
            {
                string l = E(y.substr(0,i));
                string r = E(y.substr(i+1));

                if(l!=NG && r!=NG)
                {
                    string x;
                    if(s[0]=='L') x=l;
                    if(s[0]=='R') x=r;
                    ret = MAX(ret,x);
                }
            }
        }
    }
    else if('0'<=s[0] && s[0]<='9')
    {
        rep(i,S)if(s[i]=='?') s[i]='9';
        return (num(s)?s:NG);
    }
    else if(s[0]=='?')
    {
        string candidate = "LR9";
        rep(i,3)
        {
            s[0] = candidate[i];
            string x = E(s);
            if(x!=NG) ret = MAX(ret,x);
        }
    }
    return dp[s]=ret;
}

int main()
{
    string s;
    cin >>s;
    cout << E(s) << endl;
    return 0;
}
