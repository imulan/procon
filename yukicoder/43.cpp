#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int calc_team0_place(const vector<string> &s)
{
    int n=s.size();

    vector<int> win(n,0);
    rep(i,n)
    {
        rep(j,n) win[i]+=(s[i][j]=='o');
    }

    vector<int> sorted_win(win);
    sort(all(sorted_win),greater<int>());
    sorted_win.erase(unique(all(sorted_win)), sorted_win.end());

    rep(i,sorted_win.size())
    {
        if(sorted_win[i] == win[0]) return i+1;
    }
}

int main()
{
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int r=0;
    rep(i,n)for(int j=i+1; j<n; ++j) r+=(s[i][j]=='-');

    int ans=6;
    if(r==0) ans=calc_team0_place(s);
    else
    {
        rep(mask,1<<r)
        {
            vector<string> t(s);
            int ct=0;
            rep(i,n)for(int j=i+1; j<n; ++j)if(t[i][j]=='-')
            {
                if(mask>>ct&1)
                {
                    t[i][j]='o';
                    t[j][i]='x';
                }
                else
                {
                    t[i][j]='x';
                    t[j][i]='o';
                }

                ++ct;
            }

            ans = min(ans, calc_team0_place(t));
        }
    }

    cout << ans << endl;
    return 0;
}
