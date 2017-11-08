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

char f(int a, int b)
{
    if(a==b) return ' ';
    if(a==(b+1)%3) return 'a';
    return 'b';
}

int main()
{
    ll k;
    int a,b;
    cin >>k >>a >>b;
    --a; --b;

    int A[3][3], B[3][3];
    rep(i,3)rep(j,3)
    {
        cin >>A[i][j];
        --A[i][j];
    }
    rep(i,3)rep(j,3)
    {
        cin >>B[i][j];
        --B[i][j];
    }

    ll alice = 0, bob = 0;

    int d[3][3];
    memset(d,-1,sizeof(d));
    d[a][b] = 0;
    int ct = 1;
    while(k>0)
    {
        char r = f(a,b);
        if(r=='a') ++alice;
        if(r=='b') ++bob;
        --k;

        int na = A[a][b], nb = B[a][b];
        a = na;
        b = nb;

        if(d[a][b]!=-1) break;
        d[a][b] = ct++;
    }

    string cycle = "";
    for(int i=d[a][b]; i<ct; ++i)
    {
        rep(x,3)rep(y,3)
        {
            if(d[x][y]==i)
            {
                cycle += f(x,y);
                break;
            }
        }
    }

    // dbg(cycle);
    // dbg(k);
    // printf("%d , %d  ct %d\n", a,b,ct);
    //
    // rep(i,3)
    // {
    //     rep(j,3) printf("%3d", d[i][j]);
    //     printf("\n");
    // }

    int C = cycle.size();
    int ca = 0, cb = 0;
    rep(i,C)
    {
        if(cycle[i]=='a') ++ca;
        if(cycle[i]=='b') ++cb;
    }

    alice += ca*(k/C);
    bob += cb*(k/C);

    k%=C;
    rep(i,k)
    {
        if(cycle[i]=='a') ++alice;
        if(cycle[i]=='b') ++bob;
    }

    cout << alice << " " << bob << endl;
    return 0;
}
