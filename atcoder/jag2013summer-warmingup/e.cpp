#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> P;
typedef pair<int,P> PP;

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int h,w;
int fie[31][31];
int sx,sy,gx,gy;
int cost[31][31];
vector<P> vo[8];
vector<P> vi[8];
vector<PP> G[901];

int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        string str;
        cin >> str;
        for(int j=0;j<w;j++){
            if(str[j]=='#'){
                fie[i][j]=-1;
            }
            if(str[j]=='^'){
                sy=i;
                sx=j;
            }
            if(str[j]=='$'){
                gx=j;
                gy=i;
            }
            if(str[j]>='a' && str[j]<='h'){
                fie[i][j]=1+(str[j]-'a');
                vo[(str[j]-'a')].push_back(P(i,j));
            }
            if(str[j]>='A' && str[j]<='H'){
                fie[i][j]=11+(str[j]-'A');
                vi[(str[j]-'A')].push_back(P(i,j));
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(fie[i][j]==-1)continue;
            for(int k=0;k<4;k++){
                int nx=dx[k]+j;
                int ny=dy[k]+i;
                if(nx<0 || nx>=w || ny<0 || ny>=h)continue;
                if(fie[ny][nx]==-1 || fie[ny][nx]>=10)continue;
                G[i*w+j].push_back()
            }
        }
    }
    return 0;
}