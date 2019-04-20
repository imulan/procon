#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

int n;
ll a,b;
double dp[3005][3005];

double calc(int i,int j,int f){
    if(dp[i][j]>=0.0)return dp[i][j];
    if(i+j==n)return 0.0;
    if(f==0){
        double res=2.0/((a+1-i)*2.0+(b-j));
        if(i<a)res+=calc(i+1,j,f)*(a-i)*2.0/((a+1-i)*2.0+(b-j));
        if(j<b)res+=calc(i,j+1,f)*(b-j)/((a+1-i)*2.0+(b-j));
        return dp[i][j]=res;
    }else{
        double res=1.0/((a-i)*2.0+(b+1-j));
        if(i<a)res+=calc(i+1,j,f)*(a-i)*2.0/((a-i)*2.0+(b+1-j));
        if(j<b)res+=calc(i,j+1,f)*(b-j)/((a-i)*2.0+(b+1-j));
        return dp[i][j]=res;
    }
}

void solve(istream &fin, ostream &fout){
    fin >> n >> a>> b;
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            dp[i][j]=-1.0;
        }
    }
    double a1=calc(0,0,0);
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            dp[i][j]=-1.0;
        }
    }
    double b1=calc(0,0,1);
    fout << setprecision(10) << a1 << endl;
    fout << setprecision(10) << b1 << endl;
}

int main(){
#ifdef ONLINE_JUDGE
    ifstream ifs("bonus.in");
    ofstream ofs("bonus.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
#else
    solve(cin, cout);
#endif
    return 0;
}