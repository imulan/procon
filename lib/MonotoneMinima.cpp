const int N = 2002;
const ll INF = LLONG_MAX/3;

ll f[N][N];

ll dp[N],nx[N];
int midx[N];
void minima(int ly, int ry, int lx, int rx){
    if(ly > ry) return;
    if(ly == ry){
        int idx = lx;
        ll v = dp[lx]+f[lx+1][ly];
        for(int j=lx+1; j<=rx; ++j){
            ll tv = dp[j]+f[j+1][ly];
            if(tv<v){
                idx = j;
                v = tv;
            }
        }
        nx[ly] = v;
        midx[ly] = idx;
        return;
    }

    int my = (ly+ry)/2;
    minima(my,my,lx,rx);
    minima(ly,my-1,lx,midx[my]);
    minima(my+1,ry,midx[my],rx);
}
