#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define T first
#define W second

#define dbg(x) cout<<#x"="<<x<<endl
#define rep1(i,n) for(int (i)=1;(i)<=(int)(n);++(i))

typedef pair<int,int> P;

// <to, weight>
pair<int, int> node[2000][2];

int x[2000], y[2000], z[2000];
bool visited[2000];

int main()
{
    int n,k,s;
    while(cin>>n>>k>>s, n|k|s){
        fill(node[0],node[2000],P(-1,0));
        rep(i,n){
            scanf("%d %d %d", &x[i], &y[i], &z[i]);
        }

        if(k==1){
            cout<< 6*s*s <<endl; continue;
        }

        // input
        rep(i,n){
            for(int j=i+1; j<n; j++){
                int dx=abs(x[i]-x[j]);
                int dy=abs(y[i]-y[j]);
                int dz=abs(z[i]-z[j]);
                if(dx<s && dy<s && dz<s){
                    dx = s-dx;
                    dy = s-dy;
                    dz = s-dz;
                    int weight = 2*(dx*dy+dy*dz+dz*dx);
                    cout<<i<<","<<j<<","<<weight<<endl;
                    int idx=0;
                    // i
                    if(node[i][idx].T!=-1) idx=1;
                    node[i][idx].T =j;
                    node[i][idx].W =weight;
                    // j
                    idx=0;
                    if(node[j][idx].T!=-1) idx=1;
                    node[j][idx].T =i;
                    node[j][idx].W =weight;
                }
            }
        }

        fill(visited, visited+2000, false);
        int maxw = 0;
        rep(i,n){
            if(visited[i]) continue;
            if(node[i][0].T==-1) continue;

            int idx=node[i][0].T;
            int lastIdx=i;
            bool lp=false; //loop?
            int cnt=1;
            while(node[idx][1].T!=-1){
                int ii=0;
                if(node[idx][ii].T==lastIdx) ii=1;
                lastIdx=idx;
                idx=node[idx][ii].T;
                if(idx==i){ lp=true; break; }
                cnt++;
            }
            // idx is start node.

            if(lp){
                if(cnt<k) continue;
                // loop
                // idx = i, both start node.
                int wt=node[idx][0].W;
                queue<int> q;
                q.push(wt);
                lastIdx=idx;
                idx = node[idx][0].T;
                while((int)q.size()<k){
                    visited[idx]=true;
                    int ii=0;
                    if(node[idx][ii].T==lastIdx) ii=1;
                    lastIdx=idx;
                    idx=node[idx][ii].T;
                    wt+=node[idx][ii].W;
                    q.push(node[idx][ii].W);
                }

                if(cnt==k){
                    // int ii=0;
                    // if(node[idx][ii].T==lastIdx) ii=1;
                    // lastIdx=idx;
                    // idx=node[idx][ii].T;
                    // wt+=node[idx][ii].W;

                    maxw=max(maxw, wt);
                    continue;
                }

                maxw=max(maxw, wt - q.back());
                wt-=q.front(); q.pop();

                rep(loops, cnt){
                    visited[idx]=true;
                    int ii=0;
                    if(node[idx][ii].T==lastIdx) ii=1;
                    lastIdx=idx;
                    idx=node[idx][ii].T;
                    wt+=node[idx][ii].W;
                    q.push(node[idx][ii].W);
                    maxw=max(maxw, wt-q.back());
                    wt-=q.front(); q.pop();
                }


            } else {
                // straight
                // idx is start node.
                bool flg=true;
                int wt=node[idx][0].W;
                queue<int> q;
                q.push(wt);
                lastIdx=idx;
                idx = node[idx][0].T;
                while((int)q.size()<k){
                    visited[idx]=true;
                    int ii=0;
                    if(node[idx][ii].T==lastIdx) ii=1;
                    if(node[idx][ii].T==-1){ flg=false; break; }
                    lastIdx=idx;
                    idx=node[idx][ii].T;
                    wt+=node[idx][ii].W;
                    q.push(node[idx][ii].W);
                }
                if(!flg) continue;

                maxw=max(maxw, wt-q.back());
                wt-=q.front(); q.pop();
                while(node[idx][1].T!=-1){
                    visited[idx]=true;
                    int ii=0;
                    if(node[idx][ii].T==lastIdx) ii=1;
                    lastIdx=idx;
                    idx=node[idx][ii].T;
                    wt+=node[idx][ii].W;
                    q.push(node[idx][ii].W);
                    maxw=max(maxw, wt-q.back());
                    wt-=q.front(); q.pop();
                }

            }

        }

        int res;
        if(maxw==0) res=-1;
        else res = 6*s*s*k - maxw;
        cout<<res<<endl;

    }

    return 0;
}
