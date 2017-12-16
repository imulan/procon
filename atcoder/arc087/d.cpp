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

const int N = 16010;
bool dp[N],nx[N];
vector<int> v[2];

const int P = 8000;


bool solve(int pos, int id)
{
    // dbg(pos);
    // dbg(v[id]);
    fill(dp,dp+N,false);
    dp[P] = true;
    rep(i,v[id].size())
    {
        fill(nx,nx+N,false);

        int w = v[id][i];
        rep(j,N)if(dp[j])
        {
            int nj = j+w;
            if(nj<N) nx[nj]=true;

            nj = j-w;
            if(nj>=0) nx[nj]=true;
        }

        rep(j,N) dp[j]=nx[j];
    }

    return dp[pos+P];
}

int main()
{
    string s;
    int x,y;
    cin >>s >>x >>y;

    int n = s.size();
    int idx = 0;
    while(idx<n && s[idx]=='F')
    {
        --x;
        ++idx;
    }

    s = s.substr(idx);
    s += 'T';
    n = s.size();

    int st = 1;
    int dir = 1;
    while(st<n)
    {
        idx = st;
        while(idx<n && s[idx]=='F') ++idx;
        v[dir].pb(idx-st);
        // dbg(st);
        // dbg(idx);
        st = idx+1;
        dir = !dir;
    }

    string ans = "No";
    if(solve(x,0) && solve(y,1)) ans = "Yes";
    cout << ans << endl;
    return 0;
}
