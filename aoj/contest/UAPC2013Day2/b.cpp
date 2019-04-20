#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,m;
int a[20][20];
int tmp[20][20];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void rotate(int r,int c,int s){
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            tmp[j][s-1-i]=a[i+r][j+c];
        }
    }
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            a[r+i][c+j]=tmp[i][j];
        }
    }
}

void dfs(int r,int c,int col){
    a[r][c]=1-a[r][c];
    for(int i=0;i<4;i++){
        int nx=c+dx[i];
        int ny=r+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(a[ny][nx]==col){
                dfs(ny,nx,col);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        int t;
        scanf("%d",&t);
        if(t==0){
            int r,c,s,ang;
            scanf("%d%d%d%d",&r,&c,&s,&ang);
            r--;
            c--;
            for(int j=0;j<ang;j+=90){
                rotate(r,c,s);
            }
        }
        if(t==1){
            int r,c,s;
            scanf("%d%d%d",&r,&c,&s);
            r--;
            c--;
            for(int j=0;j<s;j++){
                for(int k=0;k<s;k++){
                    a[r+j][c+k]=1-a[r+j][c+k];
                }
            }
        }
        if(t==2){
            int r;
            scanf("%d",&r);
            r--;
            for(int j=0;j<n;j++){
                tmp[0][(n-1+j)%n]=a[r][j];
            }
            for(int j=0;j<n;j++){
                a[r][j]=tmp[0][j];
            }
        }
        if(t==3){
            int r;
            scanf("%d",&r);
            r--;
            for(int j=0;j<n;j++){
                tmp[0][(j+1)%n]=a[r][j];
            }
            for(int j=0;j<n;j++){
                a[r][j]=tmp[0][j];
            }
        }
        if(t==4){
            int r,c;
            scanf("%d%d",&r,&c);
            r--;
            c--;
            dfs(r,c,a[r][c]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d%c",a[i][j],(j+1)==n?'\n':' ');
        }
    }
    return 0;
}
