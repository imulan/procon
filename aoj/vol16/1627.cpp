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

using pi = pair<int,int>;

int n;
int ans;

vector<int> w,r;
vector<pi> b;
int B;

const int N = 9;
int res[N][N];

void dfs(int d){
    if(d==B){
        rep(i,n)if(w[i]!=n/2) return;
        ++ans;
        return;
    }

    int x = b[d].fi, y = b[d].se;
    if(res[x][y]==0){
        rep(i,2){
            ++w[x];
            --r[x];
            --r[y];

            bool valid = true;
            for(int j:{x,y}){
                if(w[j]+r[j]<n/2 || w[j]>n/2) valid = false;
            }
            if(valid) dfs(d+1);

            --w[x];
            ++r[x];
            ++r[y];
            swap(x,y);
        }
    }
    else dfs(d+1);
}

int main(){
    while(cin >>n,n){
        memset(res,0,sizeof(res));
        w = vector<int>(n);
        r = vector<int>(n,n-1);

        int m;
        cin >>m;
        rep(i,m){
            int x,y;
            cin >>x >>y;
            --x;
            --y;

            res[x][y] = 1;
            res[y][x] = -1;

            ++w[x];
            --r[x];
            --r[y];
        }

        ans = 0;
        b.clear();
        rep(i,n)for(int j=i+1; j<n; ++j) b.pb({i,j});
        B = b.size();
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
