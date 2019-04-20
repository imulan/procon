#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int sx,sy;
int x[2],y[2];

int main(){
    scanf("%d%d%d%d%d%d",&sx,&sy,&x[0],&y[0],&x[1],&y[1]);
    int ans=2000*2000*4;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans=min(ans,(sx-x[i])*(sx-x[i])+(sy-y[j])*(sy-y[j]));
        }
    }
    if(x[0]<=sx && sx<=x[1]){
        ans=min(ans,(sy-y[0])*(sy-y[0]));
        ans=min(ans,(sy-y[1])*(sy-y[1]));
    }
    if(y[0]<=sy && sy<=y[1]){
        ans=min(ans,(sx-x[0])*(sx-x[0]));
        ans=min(ans,(sx-x[1])*(sx-x[1]));
    }
    printf("%.10f\n",sqrt((double)ans));
    return 0;
}

