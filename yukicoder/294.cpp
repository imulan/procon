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

const int N=25;

int main()
{
    //Combinationの計算
    int C[N][N];
    C[0][0]=1;
    for(int i=1; i<N; ++i)
    {
        C[i][0]=1;
        C[i][i]=1;
        for(int j=1; j<i; ++j) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }

    int n;
    cin >>n;

    int ct=0;
    string ans="5";

    //桁数はi+1(一番下は5で確定)
    for(int i=2; i<N; ++i)
    {
        //i+1桁の数でSuperFizzBuzzである数
        int tmp=0;
        for(int j=2; j<=i; j+=3) tmp+=C[i][j];

        if(ct+tmp<n) ct+=tmp;
        else
        {
            //この桁で答えが確定する
            rep(mask,1<<i)
            {
                if(__builtin_popcount(mask)%3==2) ++ct;
                if(ct==n)
                {
                    rep(j,i)
                    {
                        if(mask>>j&1) ans="5"+ans;
                        else ans="3"+ans;
                    }
                    break;
                }
            }
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
