#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> P;

struct data{
    int y,x;
    int bit;
    int s;
    data(){
    }
    data(int yy,int xx,int bb,int ss){
        x=xx;
        y=yy;
        bit=bb;
        s=ss;
    }
};

int h,w,L;
bool wall[32][25][25];
bool trap[25][25];
int swi[25][25];
P st,g;
int dp[25][25][32][3];
bool pus[6];

queue<data> que;

bool isok(int y,int x,int bit,int s){
    if(y<0 || y>=h || x<0 || x>=w)return false;
    if(s==0){
        if(trap[y][x])return false;
        if(wall[bit][y][x])return false;
    }
    if(s==1){
        for(int i=0;i<L;i++){
            if(x+i>=w)return false;
            if(wall[bit][y][x+i])return false;
        }
    }
    if(s==2){
        for(int i=0;i<L;i++){
            if(y+i>=h)return false;
            if(wall[bit][y+i][x])return false;
        }
    }
    return true;
}

int upd(int y,int x,int bit,int s){
    memset(pus,false,sizeof(pus));
    if(s==0){
        pus[swi[y][x]]=true;
    }
    for(int i=0;i<5;i++){
        if(pus[i+1]){
            bit^=(1<<i);
        }
    }
    return bit;
}


int check(int y,int x,int bit,int s){
    if(!isok(y,x,bit,s))return -1;
    int nbit=upd(y,x,bit,s);
    if(!isok(y,x,nbit,s))return -1;
    return nbit;
}

void trys(int y,int x,int bit,int s,int val){
    int nbit=check(y,x,bit,s);
    if(nbit>=0 && dp[y][x][nbit][s]==-1){
        dp[y][x][nbit][s]=val+1;
        que.push(data(y,x,nbit,s));
    }
}

int bfs(){
    memset(dp,-1,sizeof(dp));
    que.push(data(st.first,st.second,31,0));
    dp[st.first][st.second][31][0]=0;
    while(que.size()){
        data d=que.front();
        que.pop();
        if(d.x==g.second && d.y==g.first && d.s==0)return dp[d.y][d.x][d.bit][d.s];
        int val=dp[d.y][d.x][d.bit][d.s];
        if(d.s==0){
            trys(d.y,d.x-L,d.bit,1,val);
            trys(d.y,d.x+1,d.bit,1,val);
            trys(d.y-L,d.x,d.bit,2,val);
            trys(d.y+1,d.x,d.bit,2,val);
        }
        if(d.s==1){
            trys(d.y,d.x-1,d.bit,0,val);
            trys(d.y,d.x+L,d.bit,0,val);
            trys(d.y-1,d.x,d.bit,1,val);
            trys(d.y+1,d.x,d.bit,1,val);
        }
        if(d.s==2){
            trys(d.y-1,d.x,d.bit,0,val);
            trys(d.y+L,d.x,d.bit,0,val);
            trys(d.y,d.x-1,d.bit,2,val);
            trys(d.y,d.x+1,d.bit,2,val);
        }

    }
    return -1;
}

int main(){
    scanf("%d%d%d",&h,&w,&L);
    for(int i=0;i<h;i++){
        string str;
        cin >> str;
        for(int j=0;j<w;j++){
            if(str[j]=='S'){
                st=P(i,j);
            }
            if(str[j]=='G'){
                g=P(i,j);
            }
            if(str[j]>='a' && str[j]<='e'){
                int v=(str[j]-'a');
                for(int k=0;k<32;k++){
                    if(k>>v & 1){
                        wall[k][i][j]=true;
                    }
                }
            }
            if(str[j]>='A' && str[j]<='E'){
                swi[i][j]=(str[j]-'A')+1;
            }
            if(str[j]=='^'){
                trap[i][j]=true;
            }
            if(str[j]=='#'){
                for(int k=0;k<32;k++){
                    wall[k][i][j]=true;
                }
            }
        }
    }
    printf("%d\n",bfs());
    return 0;
}
