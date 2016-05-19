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

int NOT(int x)
{
    if(x==0) return 2;
    else if(x==1) return 1;
    else return 0;
}

int AND(int x, int y)
{
    if(x==0 || y==0) return 0;
    else if(x==1 || y==1) return 1;
    else return 2;
}

int OR(int x, int y)
{
    if(x==2 || y==2) return 2;
    else if(x==1 || y==1) return 1;
    else return 0;
}

int formula(string s)
{
    if(s.size()==1) return s[0]-'0';
    else
    {
        if(s[0]=='(' && s[s.size()-1]==')')
        {
            string t=s.substr(1,s.size()-2);
            //cout << "er : "<<t<<endl;
            int b=0;
            int op=-1;
            int now=0;
            while(now<t.size())
            {
                if(t[now]=='(') ++b;
                else if(t[now]==')') --b;
                else if(b==0)
                {
                    if(t[now]=='+')
                    {
                        op=0;
                        break;
                    }
                    if(t[now]=='*')
                    {
                        op=1;
                        break;
                    }
                }

                ++now;
            }

            string x=t.substr(0,now), y=t.substr(now+1);

            if(op==0) return OR(formula(x),formula(y));
            if(op==1) return AND(formula(x),formula(y));
        }
        else if(s[0]=='-') return NOT(formula(s.substr(1)));
    }

    return 0;
}

int main()
{
    string s;
    while(cin >>s)
    {
        if(s==".") break;

        int ans=0;
        rep(i,3)rep(j,3)rep(k,3)
        {
            string t=s;
            rep(x,s.size())
            {
                if(t[x]=='P') t[x]=i+'0';
                if(t[x]=='Q') t[x]=j+'0';
                if(t[x]=='R') t[x]=k+'0';
            }

            if(formula(t)==2) ++ans;
        }

        printf("%d\n", ans);
    }
    return 0;
}
