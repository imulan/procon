#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    while(cin >>n,n)
    {
        string s;
        cin >>s;
        vector<int> a(n), b(n);
        rep(i,n)
        {
            cin >>a[i] >>b[i];
            --a[i]; --b[i];
        }

        for(int i=n-1; i>=0; --i)
        {
            int d=b[i]-a[i];
            swap(s[a[i]],s[b[i]]);

            s[a[i]] = ((s[a[i]]-'a'+d)%26)+'a';
            s[b[i]] = ((s[b[i]]-'a'+d)%26)+'a';
        }

        cout << s << endl;
    }
    return 0;
}
