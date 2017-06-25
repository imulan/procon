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

int mod;

inline int mod_pow(int x, int n)
{
    int r=1;
    while(n)
    {
        if(n&1) (r*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return r;
}

inline int mod_inv(int x)
{
    return mod_pow(x,mod-2);
}

inline int ADD(int x, int y)
{
    return (x+y)%mod;
}

inline int SUB(int x, int y)
{
    return (x-y+mod)%mod;
}

inline int MUL(int x, int y)
{
    return (x*y)%mod;
}

inline int DIV(int x, int y)
{
    return MUL(x,mod_inv(y));
}

int pr(string x)
{
    if('0'<=x[0] && x[0]<='9') return 0;
    if(x=="*" || x=="/") return 1;
    if(x=="+" || x=="-") return 2;
    return 3;
}

int calc(string s)
{
    vector<string> v;

    int SZ = s.size();
    int idx = 0;
    while(idx<SZ)
    {
        if('0'<=s[idx] && s[idx]<='9')
        {
            int st = idx;
            while(idx<SZ && '0'<=s[idx] && s[idx]<='9') ++idx;
            v.pb(s.substr(st,idx-st));
        }
        else
        {
            v.pb(s.substr(idx,1));
            ++idx;
        }
    }

    stack<string> P,S;
    for(const auto &x:v)
    {
        if(x=="(") S.push(x);
        else if(x==")")
        {
            while(!S.empty())
            {
                string now = S.top();
                S.pop();
                if(now=="(") break;
                else P.push(now);
            }
        }
        else
        {
            bool done = false;
            while(!S.empty())
            {
                string now = S.top();
                S.pop();

                if(pr(x) >= pr(now)) P.push(now);
                else
                {
                    S.push(now);
                    S.push(x);
                    done = true;
                    break;
                }
            }
            if(!done) S.push(x);
        }
    }
    while(!S.empty())
    {
        P.push(S.top());
        S.pop();
    }

    stack<int> val;
    stack<string> revP;
    while(!P.empty())
    {
        revP.push(P.top());
        P.pop();
    }
    while(!revP.empty())
    {
        string pp = revP.top();
        revP.pop();

        if('0'<=pp[0] && pp[0]<='9') val.push(atoi(pp.c_str()));
        else
        {
            int x = val.top();
            val.pop();
            int y = val.top();
            val.pop();

            if(pp=="/")
            {
                if(x==0) return -1;
                val.push(DIV(y,x));
            }
            else if(pp=="*") val.push(MUL(y,x));
            else if(pp=="+") val.push(ADD(y,x));
            else if(pp=="-") val.push(SUB(y,x));
        }
    }

    return val.top();
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s=="0:") break;

        string t="";
        for(const auto &c:s)if(c!=' ') t+=c;
        
        int idx = t.find(":");

        mod = atoi(t.substr(0,idx).c_str());
        s = t.substr(idx+1);

        int ans = calc(s);
        if(ans == -1) cout << "NG" << endl;
        else cout << s << " = " << ans << " (mod " << mod << ")" << endl;
    }
    return 0;
}
