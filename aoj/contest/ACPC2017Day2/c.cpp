#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

using ps = pair<string,string>;

bool is_palindrome(const string &s)
{
    int S = s.size();
    rep(i,S)if(s[i]!=s[S-1-i]) return false;
    return true;
}

bool is_rev(const string &a, const string &b)
{
    int S = a.size();
    rep(i,S)if(a[i]!=b[S-i]) return false;
    return true;
}

string rev(const string &s)
{
    string t(s);
    reverse(t.begin(),t.end());
    return t;
}

int main()
{
    int n,L;
    cin >>n >>L;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    map<string,int> ct;
    rep(i,n) ++ct[s[i]];

    priority_queue<ps,vector<ps>,greater<ps>> pq;
    rep(i,n)
    {
        if(is_palindrome(s[i]))
        {
            while(ct[s[i]]>1)
            {
                pq.push({s[i],s[i]});
                ct[s[i]]-=2;
            }
        }
        else
        {
            string r = rev(s[i]);
            while(ct[s[i]]>0 && ct[r]>0)
            {
                string a = min(s[i],r), b = max(s[i],r);
                pq.push({a,b});

                --ct[s[i]];
                --ct[r];
            }
        }
    }

    string f = "", b = "";
    while(!pq.empty())
    {
        ps p = pq.top();
        pq.pop();
        f += p.first;
        b = p.second + b;
    }

    string center = "";
    rep(i,n)if(is_palindrome(s[i]) && ct[s[i]]>0)
    {
        if(center=="") center = s[i];
        else center = min(center,s[i]);
    }

    string ans = f+center+b;
    cout << ans << endl;
    return 0;
}
