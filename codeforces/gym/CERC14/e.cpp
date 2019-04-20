#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int N = 1010;
const int M = 1<<13 + 1;

char ans[N];

bool dp[N][M];
pi par[N][M];

int lowest[M];
int highest[M];

int main(){
    for(int i=1; i<M; ++i){
        int j=1;
        while( (i&j)==0 ) j <<= 1;
        lowest[i] = j;   
        
        j = 1<<14;
        while( (i&j)==0 ) j >>= 1;
        highest[i] = j;
    }


    int T;
    scanf(" %d", &T);
    while(T--){
        int n;
        scanf(" %d", &n);
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);
        
        int suma = 0;
        rep(i,n) suma += a[i];
        if(__builtin_popcount(suma)>1){
            printf("no\n");
            continue;
        }
        
        vector<int> pre(n);
        rep(i,n-1) pre[i+1] = pre[i]+a[i];

        rep(i,n+1)rep(j,suma+1){
            dp[i][j] = false;
            par[i][j] = {-1,-1};
        }
        
        par[1][a[0]] = {0,0};
        dp[1][a[0]] = true;
        for(int i=1; i<n; ++i){
            rep(mask,M)if(dp[i][mask]){
                int rest = pre[i]-mask;
                
                /*
                printf(" NOW %d :: %d , %d\n",i,mask,rest);
                printf(" LOW %d HIGH %d\n",lowest[mask],highest[mask]);
                */
                
                // left
                if(a[i] <= lowest[mask]){
                    int nx = mask+a[i];
                    dp[i+1][nx] = true;
                    par[i+1][nx] = {mask,0};
                }
                
                // right
                if(rest==0){
                    if(highest[mask] <= a[i]){
                        int nx = mask+a[i];
                        dp[i+1][nx] = true;
                        par[i+1][nx] = {mask,1};
                    }
                    else{
                        int nr = rest+a[i];
                        if(highest[mask]==nr){
                            int nx = mask+nr;
                            dp[i+1][nx] = true;
                            par[i+1][nx] = {mask,1};
                        }
                        else{
                            dp[i+1][mask] = true;                        
                            par[i+1][mask] = {mask,1};
                        }
                    }
                }
                else{
                    if(a[i] <= lowest[rest]){
                        int nr = rest+a[i];
                        if(highest[mask]==nr){
                            int nx = mask+nr;
                            dp[i+1][nx] = true;
                            par[i+1][nx] = {mask,1};
                        }
                        else{
                            dp[i+1][mask] = true;                        
                            par[i+1][mask] = {mask,1};
                        }                        
                    }
                }
            
            }
        }
         
        bool found = false;
      
        if(dp[n][suma]){
            found = true;
            int x = n;
            int y = suma;
            while(x>0){
                assert(dp[x][y]);
                //printf("%d\n", x);
                pi nxt = par[x][y];
                
                ans[x-1] = 'l';
                if(nxt.se==1) ans[x-1] = 'r';

                --x;
                y = nxt.fi;
            }
        }
        
        if(found) rep(i,n) printf("%c",ans[i]);
        else printf("no");
        printf("\n");
    }
    return 0;
}

