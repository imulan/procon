#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> P;
typedef pair<P,P> PP;
int R,C,K;
int fie[31][31];

int main(){
    scanf("%d%d%d",&R,&C,&K);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&fie[i][j]);
        }
    }
    vector<PP> res;
    for(int i=0;i<R;i++){
        int cnt=0;
        for(int j=R-1;j>=0;j--){
            if(fie[j][i]==0)break;
            cnt++;
        }
        int po=R-1;
        if(cnt%2==1){
            int a=fie[C-1][i];
            int b=(a+1)%(K+1);
            if(b==0)b++;
            res.push_back(PP(P(1,i+1),P(b,a)));
            res.push_back(PP(P(1,i+1),P(b,b)));
            res.push_back(PP(P(1,i+1),P(b,b)));
            po--;
        }
    }
    for(int i=0;i<R;i++){
        int cnt=0;
        for(int j=R-1;j>=0;j--){
            if(fie[j][i]==0)break;
            cnt++;
        }
        //printf("%d\n",cnt);
        int po=R-1;
        if(cnt%2==1){
            po--;
        }
        for(int j=po;j>=0;j-=2){
            if(j==0)break;
            int a=fie[j-1][i];
            int b=fie[j][i];
            //printf("%d %d %d %d\n",i,j,a,b);
            if(a==0 || b==0)break;
            res.push_back(PP(P(1,i+1),P(a,b)));
        }
    }
    printf("%d\n",res.size());
    for(int i=0;i<res.size();i++){
       printf("%d %d %d %d\n",res[i].fi.fi,res[i].fi.se,res[i].se.fi,res[i].se.se);
    }
    return 0;
}
