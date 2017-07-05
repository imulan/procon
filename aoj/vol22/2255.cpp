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

vector<char> op;
set<ll> res;

inline bool num(char c){return '0'<=c && c<='9';}
inline bool alp(char c){return 'a'<=c && c<='z';}
inline bool ope(char c){return c=='+' || c=='-' || c=='*' || c=='/';}

bool valid(string s)
{
    int b=0,o=0;
    rep(i,s.size())
    {
        if(s[i]=='(') ++b;
        else if(s[i]==')') --b;
        else if(alp(s[i])) ++o;
    }
    return b==0 && o==0;
}

ll get_num(string s)
{
    int S = s.size();
    int l = 0, r = S-1;
    while(s[l]=='(') ++l;
    while(s[r]==')') --r;
    return atoll(s.substr(l,r-l+1).c_str());
}

string rmbr(string s)
{
    bool update = true;
    while(update)
    {
        update = false;
        int S = s.size();
        int idx = 0;

        string ret="";
        while(idx<S)
        {
            if(s[idx]=='(')
            {
                bool fail=false;
                int st = idx;
                ++idx;
                while(s[idx]!=')')
                {
                    if(s[idx]=='(')
                    {
                        fail = true;
                        break;
                    }
                    ++idx;
                }

                string x = s.substr(st,idx-st+1);
                if(fail)
                {
                    x = s.substr(st,idx-st);
                    ret += x;
                    continue;
                }

                if(!fail) fail = !valid(x);
                if(fail) ret += x;
                else
                {
                    update = true;
                    ret += to_string(get_num(x));
                }
            }
            else ret += s[idx];

            ++idx;
        }
        s = ret;
    }
    return s;
}

set<string> vis;
void dfs(string s)
{
    s = rmbr(s);
    if(vis.count(s)) return;
    vis.insert(s);

    int S = s.size();
    vector<int> pos;
    rep(i,S)if(alp(s[i])) pos.pb(i);

    int P = pos.size();
    if(P==0) res.insert(get_num(s));

    rep(i,P)
    {
        int xl = 0;
        if(i>0) xl = pos[i-1]+1;
        int yr = S-1;
        if(i<P-1) yr = pos[i+1]-1;

        while(s[xl]=='(') ++xl;
        while(s[yr]==')') --yr;
        string x = s.substr(xl,pos[i]-xl);
        string y = s.substr(pos[i]+1,yr-pos[i]);

        char o = op[s[pos[i]]-'a'];
        if(valid(x) && valid(y))
        {
            ll X = get_num(x), Y = get_num(y);
            if(o=='+') X+=Y;
            else if(o=='-') X-=Y;
            else if(o=='*') X*=Y;
            else if(o=='/')
            {
                if(Y==0) continue;
                X/=Y;
            }

            string t = s;
            t.replace(xl, x.size()+y.size()+1, to_string(X));
            dfs(t);
        }
    }
}

int main()
{
    string s;
    while(cin >>s,(s!="#"))
    {
        op.clear();
        rep(i,s.size())if(ope(s[i]))
        {
            op.pb(s[i]);
            s[i] = 'a'+op.size()-1;
        }

        vis.clear();
        res.clear();
        dfs(s);
        cout << res.size() << endl;
    }
    return 0;
}
