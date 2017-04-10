#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline bool is_palindrome(string s)
{
    string t=s;
    reverse(all(t));
    rep(i,s.size())
    {
        if(s[i]!=t[i]) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int k,n;
    cin >>k >>n;
    vector<string> s(k);
    vector<int> a(k);
    rep(i,k) cin >>s[i] >>a[i];

    set<string> p,np;
    map<string,priority_queue<int>> q;
    rep(i,k)
    {
        if(is_palindrome(s[i])) p.insert(s[i]);
        else np.insert(s[i]);

        q[s[i]].push(a[i]);
    }

    int ans=0;

    // 回文でないもの
    for(const auto &x:np)
    {
        string y=x;
        reverse(all(y));
        while(!q[x].empty() && !q[y].empty())
        {
            int vx = q[x].top();
            int vy = q[y].top();

            if(vx+vy>=0)
            {
                ans+=vx+vy;
                q[x].pop();
                q[y].pop();
            }
            else break;
        }
    }

    // 回文
    map<string,int> odd,even;
    for(const auto &x:p)
    {
        vector<int> v;
        while(!q[x].empty())
        {
            int val = q[x].top();
            q[x].pop();

            v.pb(val);
        }

        int V=v.size();
        int sum=0;
        for(int i=0; i+1<V; i+=2)
        {
            int add=v[i]+v[i+1];

            odd[x]=max(odd[x],sum+v[i]);
            sum+=add;
            even[x]=max(even[x],sum);
        }
        odd[x] = max(odd[x],v[0]);
        if(V%2==1) odd[x] = max(odd[x],even[x]+v[V-1]);

        // cout << "V = "<<V<<endl;
        // cout<<" "<<x<<" : "<<even[x]<<" "<<odd[x]<<endl;
    }

    int t=0;
    for(const auto &x:p) t+=even[x];

    int add=t;
    for(const auto &x:p)
    {
        int tmp=t-even[x]+odd[x];
        add = max(add,tmp);
        // cout << "  "<<tmp<<endl;
    }
    ans+=add;

    cout << ans << endl;
    return 0;
}
