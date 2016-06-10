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
    int A,B;
    cin >>A >>B;

    vector<int> a(A),b(B);
    rep(i,A) scanf(" %d", &a[i]);
    rep(i,B) scanf(" %d", &b[i]);

    int ans=0;
    //Bのカードの先頭位置
    rep(i,B)
    {
        int tmp=0;

        int now=i;
        //Aのカードを先頭から見ていき，できるだけ多く選ぶ
        rep(j,A)
        {
            if(b[now]==a[j])
            {
                ++now;
                ++tmp;
            }

            if(now==B) break;
        }

        ans=max(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}
