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

using vi = vector<int>;

const int LIM = 111;

int calc(int n, const vi &r, const vector<vi> &u, int p)
{
    int ng=0,ok=LIM;
    while(ok-ng>1)
    {
        int M = (ng+ok)/2;
        vector<vi> U(u);

        U[0][p]+=M;

        vi s(n);
        rep(i,3)
        {
            vi a(n);
            rep(j,n) a[j] = -U[j][i];
            sort(all(a));
            rep(j,n)
            {
                int idx = lower_bound(all(a),-U[j][i])-a.begin();
                s[j]-=r[idx];
            }
        }

        int score = s[0];
        sort(all(s));
        int rank = lower_bound(all(s),score)-s.begin()+1;
        if(rank<=8) ok=M;
        else ng=M;
    }
    return ok;
}

int main()
{
    int n;
    cin >>n;

    vi r(n);
    rep(i,n) cin >>r[i];

    vector<vi> u(n,vi(3));
    rep(i,n)rep(j,3) cin >>u[i][j];

    int ans = LIM;
    rep(i,3) ans = min(ans,calc(n,r,u,i));

    cout << (ans==LIM?"Saiko":to_string(ans)) << endl;
    return 0;
}
