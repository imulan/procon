#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()
#define INF 1000000000*2

typedef pair<int,int> P;

int n;
int sx,sy,tx,ty;
vector<int> x,y,ys;
vector<P> ps;
int dp[100010];

bool sorter(const P& a,const P& b){
    if(a.first==b.first)return a.second < b.second;
    else return a.first > b.first;
}

int main(){
    cin>>n;
    cin>>sx>>sy>>tx>>ty;
    rep(i,n){
        int xx,yy;
        cin>>xx>>yy;
        ps.push_back(P(xx,yy));
    }
    sort(all(ps));

    if(sx>tx){
        swap(sx,tx); swap(sy,ty);
    }

    if(sy>ty){
        sort(ps.begin(),ps.end(),sorter);
    }
    rep(i,n){
        if(min(sx,tx)<=ps[i].first&&ps[i].first<=max(sx,tx)&&min(sy,ty)<=ps[i].second&&ps[i].second<=max(sy,ty)){
            ys.push_back(ps[i].second);
        }
    }
    int m=ys.size();
    rep(i,m+1)dp[i]=INF;
    rep(i,m){
        *upper_bound(dp,dp+m,ys[i])=ys[i];
    }
    rep(i,m+1){
        if(dp[i]==INF){
            cout<<i<<endl;
            return 0;
        }
    }


    return 0;
}
