#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N=10000;

int main()
{
    int a,b,d;
    while(cin >>a >>b >>d,a)
    {
        int x=50001,y=50001;
        for(int i=-N; i<=N; ++i)
        {
            int v = d-a*i;
            if(v%b==0)
            {
                int j = v/b;
                int X = abs(i), Y = abs(j);
                if(x+y>X+Y || (x+y==X+Y && a*x+b*y>a*X+b*Y))
                {
                    x=X;
                    y=Y;
                }
            }
        }
        printf("%d %d\n", x,y);
    }
    return 0;
}
