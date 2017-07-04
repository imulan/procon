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

map<string,int> atom;
bool unk;

ll A(string s)
{
    // printf(" A:::"); dbg(s);
    int S = s.size();
    int idx = 0;
    while(idx<S && (s[idx]<'0'||'9'<s[idx])) ++idx;

    ll mul = 1;
    string name = s.substr(0,idx);
    ll ret;
    if(!atom.count(name))
    {
        unk = true;
        ret = 0;
    }
    else ret=atom[name];

    if(idx!=S) mul = atoll(s.substr(idx).c_str());
    return ret*mul;
}

ll M(string s)
{
    // dbg(s);
    int S = s.size();
    if(S==0) return 0;

    int idx = 0;

    ll ret = 0;
    if(s[0]=='(')
    {
        int b = 1;
        ++idx;
        while(b>0)
        {
            if(s[idx]=='(') ++b;
            else if(s[idx]==')') --b;
            ++idx;
        }

        ll val = M(s.substr(1,idx-2));

        int mul = 1;
        if(idx<S && '0'<=s[idx] && s[idx]<='9')
        {
            int st = idx;
            while('0'<=s[idx] && s[idx]<='9') ++idx;
            mul = atoi(s.substr(st,idx-st).c_str());
        }

        ret += val*mul;
        ret += M(s.substr(idx));
    }
    else
    {
        int st = idx;
        ++idx;
        while(idx<S && (s[idx]<'A'||'Z'<s[idx]) && s[idx]!='(') ++idx;
        ret += A(s.substr(st,idx-st));
        ret += M(s.substr(idx));
    }
    return ret;
}

int main()
{
    string s;
    while(cin >>s)
    {
        if(s=="END_OF_FIRST_PART") break;
        int v;
        cin >>v;
        atom[s] = v;
    }
    while(cin >>s)
    {
        if(s=="0") break;

        unk = false;
        ll ans = M(s);

        if(unk) cout << "UNKNOWN" << endl;
        else cout << ans << endl;
    }
    return 0;
}
