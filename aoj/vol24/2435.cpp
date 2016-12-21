#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

bool isNumber(string s)
{
    rep(i,s.size())
    {
        if(!('0'<=s[i] && s[i]<='9')) return false;
    }
    return true;
}

string solve()
{
    int m;
    cin >>m;

    map<string,vi> var;

    rep(i,m)
    {
        string name;
        int lb,rb;
        cin >>name >>lb >>rb;

        vi valid(256,0);
        for(int j=lb; j<=rb; ++j) valid[j]=1;

        var[name] = valid;
    }

    int n;
    cin >>n;
    vector<string> e(n);
    rep(i,n) cin >>e[i];

    string res="temporary_variable_for_calculation";
    int res_ct=0;
    stack<string> st;
    rep(i,n)
    {
        if(e[i]=="+" || e[i]=="-" || e[i]=="*" || e[i]=="/")
        {
            if(st.size()<2) return "error";

            string B=st.top();
            st.pop();
            string A=st.top();
            st.pop();

            // cout << A << " " << e[i] << " " << B << '\n';

            vi valA(256,0),valB(256,0);
            if(isNumber(A))
            {
                int tmp = atoi(A.c_str());
                valA[tmp] = 1;
            }
            else valA = var[A];
            if(isNumber(B))
            {
                int tmp = atoi(B.c_str());
                valB[tmp] = 1;
            }
            else valB = var[B];


            if(e[i]=="/")
            {
                if(valB[0]==1) return "error";
            }

            vi valC(256,0);
            rep(a,256)rep(b,256)if(valA[a] && valB[b])
            {
                int c=0;
                if(e[i]=="+") c=a+b;
                else if(e[i]=="-") c=a-b;
                else if(e[i]=="*") c=a*b;
                else if(e[i]=="/") c=a/b;

                c = (c+256)%256;
                valC[c] = 1;
            }

            st.push(res+to_string(res_ct));
            var[res+to_string(res_ct)] = valC;
            ++res_ct;
        }
        else st.push(e[i]);
    }

    return "correct";
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    cout << solve() << '\n';
    return 0;
}
