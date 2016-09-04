#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
    int h,w;
    cin >>h >>w;
    vector<string> a(h);
    rep(i,h) cin >>a[i];

    vector<string> r(h, string(w,'.')), b(h, string(w,'.'));

    rep(i,h)
    {
        r[i][0]='#';
        b[i][w-1]='#';
    }

    rep(i,h)
    {
        if(i%2==0)
        {
            for(int j=1; j<w-1; ++j)
            {
                r[i][j]='#';
                if(a[i][j]=='#') b[i][j]='#';
            }
        }
        else
        {
            for(int j=1; j<w-1; ++j)
            {
                b[i][j]='#';
                if(a[i][j]=='#') r[i][j]='#';
            }
        }
    }

    rep(i,h) cout << r[i] << endl;
    printf("\n");
    rep(i,h) cout << b[i] << endl;

    // printf("back\n");
    // rep(i,h)
    // {
    //     rep(j,w)
    //     {
    //         if(r[i][j]=='#' && b[i][j]=='#') printf("#");
    //         else printf(".");
    //     }
    //     printf("\n");
    // }
    return 0;
}
