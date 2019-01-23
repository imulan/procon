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

const int N = 20;
int ans[N+1][N+1];

int main(){
    for(int i=2; i<=N; ++i){
        vector<bool> vis(i+1);
        vector<int> a(i+1);
        a[0] = i;
        vis[0] = true;

        int t = 0;
        while(!vis[i-1]){
            ++t;

            vector<int> na(i+1);
            rep(j,i){
                na[j+1] += a[j]/2;
                na[0] += a[j]/2;
                na[j] += a[j]%2;

                if(!vis[j] && na[j]>0){
                    vis[j] = true;
                    ans[i][j] = t;
                }
            }

            a = na;
        }
    }

    int C = 1;
    int n,m;
    while(scanf(" %d %d", &n, &m),n) printf("Case %d: %d\n", C++, ans[n][m]);
    return 0;
}
