#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x<<"="<<x<<endl

int H,W,h,w,n;
vector<string> crt,res;
vector<bool> up,down,lefts,rights;
vector<vector<string> > s;

bool dfs(int idx){
    if(idx==n*n){
        bool ok=true;
        rep(i,H)rep(j,W)if(crt[i][j]=='.')ok=false;
        //rep(i,H)cout<<crt[i]<<endl;
        //cout<<endl;
        if(!ok)return false;
        res=crt;
        return true;
    }
    for(int i=0;i<H;i+=h){
        if(i>0&&up[idx])continue;
        if(i<H-h&&down[idx])continue;
        for(int j=0;j<W;j+=w){
            if(j>0&&lefts[idx])continue;
            if(j<W-w&&rights[idx])continue;
            //dbg(idx); dbg(i); dbg(j);
            bool ok=true;
            for(int ni=i-h+1,bi=0;ni<i+2*h-1;ni++,bi++){
                for(int nj=j-w+1,bj=0;nj<j+2*w-1;nj++,bj++){
                    if(ni<0||ni>=H||nj<0||nj>=W)continue;
                    if(s[idx][bi][bj]!='.'&&crt[ni][nj]!='.'){
                        ok=false; break;
                    }
                }
                if(!ok)break;
            }
            if(!ok)continue;
            for(int ni=i-h+1,bi=0;ni<i+2*h-1;ni++,bi++){
                for(int nj=j-w+1,bj=0;nj<j+2*w-1;nj++,bj++) {
                    if (ni < 0 || ni >= H || nj < 0 || nj >= W)continue;
                    if(crt[ni][nj]=='.')crt[ni][nj]=s[idx][bi][bj];
                }
            }
            if(dfs(idx+1))return true;
            for(int ni=i-h+1,bi=0;ni<i+2*h-1;ni++,bi++){
                for(int nj=j-w+1,bj=0;nj<j+2*w-1;nj++,bj++) {
                    if (ni < 0 || ni >= H || nj < 0 || nj >= W)continue;
                    if(s[idx][bi][bj]!='.')crt[ni][nj]='.';
                }
            }
        }
    }
    return false;
}

void solve(istream &fin, ostream &fout) {
    int k;
    fin>>k>>w>>h;
    n=(int)sqrt(k);
    H=n*h; W=n*w;
    s.resize(k,vector<string>(h*3-2));
    rep(idx,k){
        rep(i,h*3-2)fin>>s[idx][i];
    }

    up.resize(k); down.resize(k); lefts.resize(k); rights.resize(k);

    rep(idx,k){
        up[idx]=true; down[idx]=true; lefts[idx]=true; rights[idx]=true;
        for(int j=w-1;j<2*w-1;j++){
            if(s[idx][h-2][j]!='.'||s[idx][h-1][j]=='.')up[idx]=false;
            if(s[idx][2*h-2][j]=='.'||s[idx][2*h-1][j]!='.')down[idx]=false;
        }
        for(int i=h-1;i<2*h-1;i++){
            if(s[idx][i][w-2]!='.'||s[idx][i][w-1]=='.')lefts[idx]=false;
            if(s[idx][i][2*w-2]=='.'||s[idx][i][2*w-1]!='.')rights[idx]=false;
        }
        //dbg(up[idx]); dbg(down[idx]); dbg(lefts[idx]); dbg(rights[idx]);
    }
    crt.resize(H,"");
    rep(i,H)rep(j,W)crt[i]+=".";
    res.clear();
    assert(dfs(0));
    fout<<W<<" "<<H<<endl;
    rep(i,H)fout<<res[i]<<endl;
}

int main(){
#ifdef ONLINE_JUDGE
    ifstream ifs("ascii.in");
    ofstream ofs("ascii.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
#else
    solve(cin, cout);
#endif
    return 0;
}
