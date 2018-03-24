#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

string s;
int n;
int p,m;

const int N = 3000;
int num = 0;
int l[N],r[N],q[N];
map<pi,int> range;

const int M = 101;
const int INF = 10101010;

bool pl;

const pi I = {-INF,INF};
pi dp[N][M];
pi dfs(int x, int y){
    if(dp[x][y] != I) return dp[x][y];

    pi ret = I;

    int al = l[x]+1, ar = q[x]-1;
    int bl = q[x]+1, br = r[x]-1;

    // printf("CALL (%d %d) ",x,y);
    // printf(" a(%d, %d) b(%d, %d)\n",al,ar,bl,br);

    // 今注目している位置のoperatorを決定
    rep(i,2){
        int yy = y-i;
        if(yy<0) continue;

        // 左側にj個分配
        rep(j,yy+1){
            pi lch,rch;

            if(al==ar){
                if(j!=0) continue;
                int val = s[al]-'0';
                lch = {val,val};
            }
            else lch = dfs(range[{al,ar}], j);

            if(bl==br){
                if(j!=yy) continue;
                int val = s[bl]-'0';
                rch = {val,val};
            }
            else rch = dfs(range[{bl,br}], yy-j);
            if((i==0 && pl) || (i==1 && !pl)) rch = {-rch.se, -rch.fi};

            ret.fi = max(ret.fi, lch.fi+rch.fi);
            ret.se = min(ret.se, lch.se+rch.se);
        }
    }

    return dp[x][y] = ret;
}

int main(){
    cin >>s >>p >>m;
    n = s.size();

    if(n==1){
        cout << s << endl;
        return 0;
    }

    fill(l,l+N,-1);
    fill(r,r+N,-1);
    fill(q,q+N,-1);

    stack<int> st;
    rep(i,n){
        if(s[i] == '('){
            l[num] = i;
            st.push(num++);
        }
        else if(s[i] == '?'){
            q[st.top()] = i;
        }
        else if(s[i] == ')'){
            r[st.top()] = i;
            st.pop();
        }
    }

    rep(i,num) range[{l[i],r[i]}] = i;

    rep(i,N)rep(j,M) dp[i][j] = I;
    pl = (p<=m);
    cout << dfs(0,min(p,m)).fi << endl;
    return 0;
}
