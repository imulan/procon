#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline int dist2(int ax, int ay, int bx, int by)
{
    return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}

bool reach(int hx, int hy, int tx, int ty, int d, int w, int a)
{
    // 距離チェック
    if(dist2(hx,hy,tx,ty)>a*a) return false;

    // 角度チェック
    const double PI=acos(-1);
    double theta = atan2(hy-ty,hx-tx);
    double rad_w=w*PI/180, rad_d=d*PI/180;
    double l=rad_w-rad_d/2, r=rad_w+rad_d/2;

    bool ret=false;
    for(int i=-1; i<=1; ++i)
    {
        if(l<=theta+i*2*PI && theta+i*2*PI<=r) ret=true;
    }
    return ret;
}

int main()
{
    int H,R;
    while(scanf(" %d %d", &H, &R),H)
    {
        // input
        vector<int> hx(H),hy(H);
        rep(i,H) scanf(" %d %d", &hx[i], &hy[i]);

        int num[3],d[3];
        rep(i,3) scanf(" %d", &num[i]);
        rep(i,3) scanf(" %d", &d[i]);

        vector<int> tx[3],ty[3];
        rep(i,3)
        {
            tx[i] = vector<int>(num[i]);
            ty[i] = vector<int>(num[i]);
            rep(j,num[i]) scanf(" %d %d", &tx[i][j], &ty[i][j]);
        }

        vector<int> w(R), a(R);
        rep(i,R) scanf(" %d %d", &w[i], &a[i]);

        // solve
        vector<int> ct(H,0);
        rep(i,R)rep(j,H)
        {
            if(!reach(hx[j],hy[j],0,0,d[0],w[i],a[i])) continue;

            bool other=false;
            rep(k,3)rep(l,num[k]) if(reach(hx[j],hy[j],tx[k][l],ty[k][l],d[k],w[i],a[i])) other=true;

            if(!other) ++ct[j];
        }

        // output
        int max_ct=0;
        rep(i,H) max_ct=max(max_ct,ct[i]);

        if(max_ct==0) printf("NA\n");
        else
        {
            vector<int> ans;
            rep(i,H) if(max_ct == ct[i]) ans.pb(i);

            rep(i,ans.size())
            {
                if(i) printf(" ");
                printf("%d", ans[i]+1);
            }
            printf("\n");
        }
    }
    return 0;
}
