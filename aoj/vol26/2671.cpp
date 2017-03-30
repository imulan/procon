#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int is_uruu(int year)
{
    if(year%400 == 0) return 1;
    if(year%100 == 0) return 0;
    if(year%4 == 0) return 1;
    return 0;
}

int main()
{
    // 各数字ごとにどこが光るかの情報
    int bit[10] = {119,36,93,109,46,107,123,37,127,111};

    // 入力
    vector<int> mask(14,(1<<7)-1);

    int N,K;
    cin >>N >>K;
    rep(i,K)
    {
        int p,q;
        cin >>p >>q;

        mask[p] -= (1<<q);
    }

    // 時間部分についてカウント
    ll time_count[100]={};
    rep(h,24)rep(m,60)rep(s,60)
    {
        int ct=0;

        ct += __builtin_popcount(mask[8] & bit[h/10]);
        ct += __builtin_popcount(mask[9] & bit[h%10]);

        ct += __builtin_popcount(mask[10] & bit[m/10]);
        ct += __builtin_popcount(mask[11] & bit[m%10]);

        ct += __builtin_popcount(mask[12] & bit[s/10]);
        ct += __builtin_popcount(mask[13] & bit[s%10]);

        ++time_count[ct];
    }

    // 日付部分についてカウント(うるう年 0/1)
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    ll day_count[2][100]={};
    for(int m=1; m<=12; ++m)for(int d=1; d<=days[m]; ++d)
    {
        int ct = 0;

        ct += __builtin_popcount(mask[4] & bit[m/10]);
        ct += __builtin_popcount(mask[5] & bit[m%10]);

        ct += __builtin_popcount(mask[6] & bit[d/10]);
        ct += __builtin_popcount(mask[7] & bit[d%10]);

        ++day_count[0][ct];
    }
    // 2/29を考慮
    int uruu_day = 0;
    uruu_day += __builtin_popcount(mask[4] & bit[0]);
    uruu_day += __builtin_popcount(mask[5] & bit[2]);

    uruu_day += __builtin_popcount(mask[6] & bit[2]);
    uruu_day += __builtin_popcount(mask[7] & bit[9]);

    rep(i,100) day_count[1][i] = day_count[0][i];
    ++day_count[1][uruu_day];

    // 年部分についてカウント
    ll year_count[2][100]={};
    rep(y,10000)
    {
        int ct = 0;

        int ty = y;
        for(int i=3; i>=0; --i)
        {
            ct += __builtin_popcount(mask[i] & bit[ty%10]);
            ty /= 10;
        }

        ++year_count[is_uruu(y)][ct];
    }

    ll ans = 0;
    rep(yc,100)rep(dc,100)rep(tc,100)if(yc+dc+tc == N)
    {
        rep(i,2) ans += year_count[i][yc]*day_count[i][dc]*time_count[tc];

    }
    cout << ans << endl;
    return 0;
}
