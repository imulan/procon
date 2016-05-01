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

int main()
{
    int times;
    cin >>times;
    rep(T,times)
    {
        string s;
        cin >>s;

        int ct[26]={0};
        rep(i,s.size()) ++ct[s[i]-'A'];

        vector<int> ans;

        int order[10]={0,2,4,6,8,1,3,5,7,9};
        string id="ZOWTUFXSGI";
        string t[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        rep(j,10)
        {
            int n=order[j];
            char f=id[n];
            while(ct[f-'A']>0)
            {
                ans.pb(n);
                rep(k,t[n].size()) --ct[t[n][k]-'A'];
            }
        }

        sort(all(ans));

        printf("Case #%d: ",T+1);
        for(const auto &x:ans) printf("%d",x);
        printf("\n");
    }
    return 0;
}
