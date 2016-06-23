#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<pi,vector<int>> P;

int n;
string s[12];

int dfs(int now, int carry, const vector<int> &use)
{
  // cout<<now<<endl;
    // rep(i,use.size()) if(use[i]!=-1) printf("%c=%d, ",'a'+use[i],i);
    // cout<<endl;
    if(now==0)
    {
        if(carry==0) return 1;
    }

    int ret=0;

    vector<char> vv;
    rep(i,n-1)
    {
        if('a'<=s[i][now] && s[i][now]<='j')
        {
            bool found=false;
            rep(j,10) if(use[j]==s[i][now]-'a') found=true;
            if(!found) vv.pb(s[i][now]);
        }
    }
    sort(all(vv));
    vv.erase(unique(all(vv)),vv.end());

    int VV=vv.size();

    vector<int> perm(10);
    rep(i,10) perm[i]=i;

    do
    {
        bool valid=true;
        vector<int> nxuse(use);

        int point=-1;
        //文字vv[i]をperm[i]に割り当て
        rep(i,VV)
        {
            if(nxuse[perm[i]]==-1) nxuse[perm[i]]=vv[i]-'a';
            else
            {
                point=i;
                valid=false;
                break;
            }
        }

        if(point!=-1)
        {
            //printf("piyo, %d\n",point);

            ++point;
            sort(perm.begin()+point,perm.end());
            reverse(perm.begin()+point,perm.end());
        }
        else
        {
            if(now<8)
            {
              rep(i,n)
              {
                if(nxuse[0]==s[i][now]-'a' && s[i][now-1]=='0') valid=false;
              }
            }

            if(valid)
            {
                int sum=carry;
                rep(i,n-1)
                {
                  rep(j,10) if(nxuse[j]==s[i][now]-'a') sum+=j;
                }

                char focus=s[n-1][now];
                if(focus=='0') return (sum==0 && carry==0)?1:0;

                int idx=-1;
                rep(i,10)
                {
                    if(nxuse[i]==focus-'a')
                    {
                        idx=i;
                        break;
                    }
                }


                if(idx==-1)
                {
                    int r=sum%10;
                    if(nxuse[r]==-1)
                    {
                        nxuse[r]=s[n-1][now]-'a';  // add this line
                        if(r==0 && s[n-1][now-1]=='0');
                        else ret+=dfs(now-1,sum/10,nxuse);
                    }
                }
                else
                {
                    if(sum%10==idx)
                    {
                        if(idx==0 && s[n-1][now-1]=='0');
                        else ret+=dfs(now-1,sum/10,nxuse);
                    }
                }
            }

            sort(perm.begin()+VV,perm.end());
            reverse(perm.begin()+VV,perm.end());
        }
        /*
        rep(i,10) printf(" %d", perm[i]);
        printf("\n");
        printf("ed\n");
        */

        //if(now==8) printf("ret=%d\n", ret);
    }
    while(next_permutation(all(perm)));

    //printf(" ret now= %d\n", now);

    return ret;
}

int main()
{
    while(cin >>n,n)
    {
        rep(i,n) cin >>s[i];

        vector<char> var;
        rep(i,n)rep(j,s[i].size()) var.pb(s[i][j]);

        sort(all(var));
        var.erase(unique(all(var)),var.end());

        //変換
        map<char,char> m;
        rep(i,var.size()) m[var[i]]='a'+i;
        rep(i,n)rep(j,s[i].size()) s[i][j]=m[s[i][j]];

        //桁を揃える
        rep(i,n)
        {
            while(s[i].size()<9) s[i]="0"+s[i];
        }

        //rep(i,n) cout<<s[i]<<endl;
        vector<int> u(10,-1);

        cout << dfs(8,0,u) << endl;
    }
    return 0;
}
