#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()

double N,M;
double R,xx0,yy0,xx1,yy1;

int main(){
    cin>>M>>N>>R;
    cin>>xx0>>yy0>>xx1>>yy1;

    if(yy0<yy1){
        swap(yy0,yy1); swap(xx0,xx1);
    }

    double res=(R/N)*(yy0-yy1);
    double r=(R/N)*yy1;
    res+=min((acos(-1.0)*r/M)*abs(xx0-xx1),r*2);

    printf("%.10f\n",res);

    return 0;
}
