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

const int N = 7400000;

int main()
{
    int m,n;
    while(scanf(" %d %d", &m, &n),m)
    {
        vector<bool> x(N);
        int i;
        for(i=m; i<N; ++i)
        {
            if(!x[i])
            {
                for(int j=i; j<N; j+=i) x[j]=true;
                --n;
                if(n==0) break;
            }
        }

        while(x[i]==1) ++i;
        cout << i << endl;
    }
    return 0;
}
