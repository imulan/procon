#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

//arrow
inline int AR(int x, int y)
{
    if(x==1 && y==0) return 0;
    return 1;
}

int formula(string s)
{
    if(s.size()==1) return s[0]-'0';
    if(s[0]=='-') return !formula(s.substr(1));

    //bracket
    string t=s.substr(1,s.size()-2);

    int idx=0;
    int br=0;
    while(idx<t.size())
    {
        if(t[idx]=='(') ++br;
        if(t[idx]==')') --br;

        if(br==0)
        {
            if(t[idx]=='*')
            {
                string x=t.substr(0,idx);
                string y=t.substr(idx+1);
                return formula(x)&formula(y);
            }
            else if(t[idx]=='+')
            {
                string x=t.substr(0,idx);
                string y=t.substr(idx+1);
                return formula(x)|formula(y);
            }
            else if(idx+1<t.size() && t[idx]=='-' && t[idx+1]=='>')
            {
                string x=t.substr(0,idx);
                string y=t.substr(idx+2);
                return AR(formula(x),formula(y));
            }
        }

        ++idx;
    }

    return 0;
}

int main()
{
    string eq;
    while(cin >>eq,(eq!="#"))
    {
        //variables
        set<char> vars;
        rep(i,eq.size())
        {
            if('a'<=eq[i] && eq[i]<='k')
            {
                if(vars.find(eq[i])==vars.end()) vars.insert(eq[i]);
            }
        }

        //cut equation to 2 formulae
        int e=0;
        while(e<eq.size() && eq[e]!='=') ++e;
        string x=eq.substr(0,e), y=eq.substr(e+1);

        //translate "T"(1) and "F"(0)
        rep(i,x.size())
        {
            if(x[i]=='T') x[i]='1';
            if(x[i]=='F') x[i]='0';
        }
        rep(i,y.size())
        {
            if(y[i]=='T') y[i]='1';
            if(y[i]=='F') y[i]='0';
        }

        int n=vars.size();
        bool ok=true;
        rep(mask,1<<n)
        {
            //image
            map<char,int> im;

            int ct=0;
            for(const auto &x : vars)
            {
                im[x]=(mask>>ct&1);
                ++ct;
            }

            //translation
            string nx=x,ny=y;
            rep(i,nx.size())
            {
                if('a'<=nx[i] && nx[i]<='k') nx[i]=im[nx[i]]+'0';
            }
            rep(i,ny.size())
            {
                if('a'<=ny[i] && ny[i]<='k') ny[i]=im[ny[i]]+'0';
            }

            if(formula(nx)!=formula(ny))
            {
                ok=false;
                break;
            }
        }

        string ans="NO";
        if(ok) ans="YES";
        cout << ans << endl;
    }
    return 0;
}
