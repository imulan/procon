#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<string> convert(string s)
{
    vector<string> ret;

    int i=0;
    while(s[i]!=':') ++i;
    ret.pb(s.substr(0,i));

    int st=i+1;
    i=st;
    while(st<s.size())
    {
        while(s[i]!=',' && s[i]!='.') ++i;
        ret.pb(s.substr(st,i-st));
        st=i+1;
        i=st;
    }

    return ret;
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<vector<string>> s(n);
        rep(i,n)
        {
            string tmp;
            cin >>tmp;
            s[i]=convert(tmp);
        }

        map<string,int> group2id;
        rep(i,n) group2id[s[i][0]]=i;

        set<string> names;
        queue<int> que;
        for(int i=1; i<s[0].size(); ++i)
        {
            if(group2id.find(s[0][i]) == group2id.end()) names.insert(s[0][i]);
            else que.push(group2id[s[0][i]]);
        }

        vector<bool> vis(n);
        vis[0]=true;

        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            for(int i=1; i<s[v].size(); ++i)
            {
                if(group2id.find(s[v][i]) == group2id.end()) names.insert(s[v][i]);
                else
                {
                    int nx=group2id[s[v][i]];
                    if(!vis[nx])
                    {
                        vis[nx]=true;
                        que.push(nx);
                    }
                }
            }
        }

        cout << names.size() << endl;
    }
    return 0;
}
