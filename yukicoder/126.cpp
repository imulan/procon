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
    int a,b,s;
    cin >>a >>b >>s;

    int ans=0;
    if(s==1)
    {
        //必ずAが来る
        if(a==0) ans=2;
        else ans=a;
    }
    else
    {
        if(abs(a-s)>abs(b-s))
        {//現在のフロアでボタンを押すとBが来る時
            if(a>0)
            {
                //Aのあるフロアまで移動してから地下へ
                ans=abs(b-s)+abs(s-a)+a;
                //とにかくbで1階まで行ってからAを呼ぶ
                ans=min(ans, abs(b-s)+s-1+a);
            }
            else ans=abs(b-s)+s-1+2;
        }
        else
        {//現在のフロアでボタンを押すとAが来る時
            //そのまま移動
            ans=abs(a-s)+s;
        }
    }
    cout << ans << endl;
    return 0;
}
