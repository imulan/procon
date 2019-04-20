#include <bits/stdc++.h>
using namespace std;
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using ll = long long;
using pi = pair<ll,int>;

const double EPS = 1e-8;

const ll INF = LLONG_MAX/3;
ll mul(ll x, ll y)
{
    if(x==0 || y==0) return 0;

    // x*y>INF
    if(x>INF/y) return INF;
    return x*y;
}

inline bool IN(ll L, ll R, ll MM, ll M, int n)
{
    if(M==0) return (L<n && n<R);
    return (mul(L,M)<MM && MM<mul(R,M));
}

void solve(istream &ifs, ostream &ofs){
    int n,w,h,m;
    ifs >>n >>w >>h >>m;

    vector<int> l(m),k(m);
    rep(i,m)
    {
        ifs >>l[i] >>k[i];
        --l[i];
        --k[i];
    }

    vector<vector<bool>> exist(h,vector<bool>(n,true));
    vector<int> L(h,0), R(h,n-1);

    int S = 0;
    rep(i,n) S += 2*i+1;

    vector<ll> mass(h,n),g(h,S);

    rep(i,m)
    {
        // printf("QUERY : %d %d\n", l[i],k[i]);
        int X = 2*k[i]+1;
        g[l[i]] -= X;
        mass[l[i]] -= 1;

        exist[l[i]][k[i]] = false;

        while(L[l[i]]<n && !exist[l[i]][L[l[i]]]) ++L[l[i]];
        while(R[l[i]]>=0 && !exist[l[i]][R[l[i]]]) --R[l[i]];

        ll mmx=0,mmy=0;
        ll mx=0,my=0;

        // printf("---- %d\n", i);

        for(int j=h-1; j>=0; --j)
        {
            int lx,rx,ly,ry;

            if(j%2==0)
            {
                ly = 0;
                ry = 2*n;
                lx = 2*L[j];
                rx = 2*R[j]+2;
            }
            else
            {
                lx = 0;
                rx = 2*n;
                ly = 2*L[j];
                ry = 2*R[j]+2;
            }

            // printf(" j %d \n", j);
            // printf("mmx mx %lld %d mmy my %lld %d\n", mmx,mx,mmy,my);
            // printf(" L R %d %d\n", L[j],R[j]);
            // printf("X[%d %d],Y[%d %d]\n", lx,rx,ly,ry);

            if(mx+my>0)
            {
                if(!IN(lx,rx,mmx,mx,n) || !IN(ly,ry,mmy,my,n))
                {
                    ofs << "yes" << endl;
                    ofs << i+1 << endl;
                    return;
                }
            }

            if(j%2==0)
            {
                mx += mass[j];
                mmx += g[j];
                my += mass[j];
                mmy += n*mass[j];
            }
            else
            {
                my += mass[j];
                mmy += g[j];
                mx += mass[j];
                mmx += n*mass[j];
            }
        }
    }

    ofs << "no" << endl;
}

int main(int args, char* argv[]){
  if(args>1){
    solve(cin, cout);
  } else {
    ifstream ifs = ifstream("jenga.in");
    ofstream ofs = ofstream("jenga.out");
    solve(ifs, ofs);
  }
  return 0;
}
