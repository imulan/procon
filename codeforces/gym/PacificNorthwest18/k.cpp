#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)

#define INF 1e18

#define dbg(x) cout<<#x<<"="<<x<<endl

double mn[1<<9],mx[1<<9];
vector<vector<int> > mvs[13];
double num[1<<9];
vector<int> tmp;

void predfs(int i,int pre,int rest){
    if(rest==0){
        mvs[i].push_back(tmp);
    }
    repl(j,pre+1,min(rest+1,10)){
        tmp.push_back(j);
        predfs(i,j,rest-j);
        tmp.pop_back();
    }
}

void dfs(int S){
    if(mn[S]!=-1)return ;
    mn[S]=0,mx[S]=0;
    repl(a,1,7)repl(b,1,7){
        int sum=a+b;
        double cmn=INF,cmx=-INF;
        rep(i,mvs[sum].size()){
            int nS=S;
            bool ok=true;
            for(int j : mvs[sum][i]){
                if((nS>>(j-1))&1){
                    nS^=1<<(j-1);
                }else ok=false;
            }
            if(!ok)continue;
            dfs(nS);
            minch(cmn,mn[nS]);
            maxch(cmx,mx[nS]);
        }
        if(cmn==INF){
            cmn=num[S]; cmx=num[S];
        }
        mn[S]+=cmn*(1.0/36.0);
        mx[S]+=cmx*(1.0/36.0);
    }
    return ;
}

int main(){
    rep(S,1<<9){
        mn[S]=-1,mx[S]=-1;
        rep(i,9){
            if((S>>i)&1){
                num[S]*=10;
                num[S]+=i+1;
            }
        }
    }
    repl(i,2,13){
        predfs(i,0,i);
    }

    int st=0;
    {
        string s;
        cin>>s;
        rep(i,s.size()){
           st|=(1<<(s[i]-'1'));
        }
    }
    int a,b;
    cin>>a>>b;
    double res[]={INF,-INF};
    vector<int> resmv[2];
    rep(i,mvs[a+b].size()){
        int nS=st;
        bool ok=true;
        for(int j : mvs[a+b][i]){
            if((nS>>(j-1))&1){
                nS^=1<<(j-1);
            }else ok=false;
        }
        if(!ok)continue;
        dfs(nS);
        if(res[0]>mn[nS]){
            res[0]=mn[nS];
            resmv[0]=mvs[a+b][i];
        }
        if(res[1]<mx[nS]){
            res[1]=mx[nS];
            resmv[1]=mvs[a+b][i];
        }
    }
    rep(i,2){
        if(res[i]==-INF||res[i]==INF){
            printf("-1 %.5f\n",num[st]);
        }else{
            rep(j,resmv[i].size()){
               printf("%d",resmv[i][j]);
            }
            printf(" %.5f\n",res[i]);
        }
    }
    return 0;
}

