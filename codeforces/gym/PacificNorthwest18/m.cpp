#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x<<"="<<x<<endl

#define eps 1e-6

ll N;
double C;
double c[30001],h[30001],p[30001],f[30001];
double H,P;
double x[30001];

bool ok(double lamda){
    double tot=0;
    rep(i,N){
        x[i]=(lamda*c[i]-f[i])/(2*h[i]*p[i]);
        tot+=x[i]*c[i];
    }
    return tot<C+eps;
}

int main(){
    scanf("%lld%lf",&N,&C);
    rep(i,N){
        scanf("%lf%lf%lf",&c[i],&h[i],&p[i]);
        H+=h[i]; P+=p[i];
    }
    double lb=0,ub=1e18;
    rep(i,N){
        f[i]=h[i]*P+p[i]*H-2*h[i]*p[i];
        lb=max(lb,f[i]/c[i]);
    }
    rep(i,100){
        double X=(lb+ub)/2.0;
        if(ok(X)) lb=X;
        else ub=X;
    }
    dbg(lb); dbg(ub);
    double resa=0,resb=0;
    rep(i,N){
        resa+=h[i]*x[i];
        resb+=p[i]*x[i];
    }
    rep(i,N){
        printf("x[i]=%.2f\n",x[i]);
    }
    printf("%.2f\n",resa*resb);
    
    return 0;
}

