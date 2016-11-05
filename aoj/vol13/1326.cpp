#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456;

int main()
{
    int p,q;
    while(cin >>p >>q,p)
    {
        vector<int> pr(p,0),pc(p,0),ps(p,0);
        vector<int> indent(p);
        rep(i,p)
        {
            string s;
            cin >>s;

            int now=0;
            while(now<s.size() && s[now]=='.') ++now;
            indent[i]=now;

            rep(j,s.size())
            {
                if(s[j]=='(') ++pr[i];
                else if(s[j]==')') --pr[i];
                else if(s[j]=='{') ++pc[i];
                else if(s[j]=='}') --pc[i];
                else if(s[j]=='[') ++ps[i];
                else if(s[j]==']') --ps[i];
            }
        }

        vector<int> qr(q,0),qc(q,0),qs(q,0);
        rep(i,q)
        {
            string s;
            cin >>s;

            rep(j,s.size())
            {
                if(s[j]=='(') ++qr[i];
                else if(s[j]==')') --qr[i];
                else if(s[j]=='{') ++qc[i];
                else if(s[j]=='}') --qc[i];
                else if(s[j]=='[') ++qs[i];
                else if(s[j]==']') --qs[i];
            }
        }

        vector<int> ans(q,INF);
        rep(x,20)rep(y,20)rep(z,20)
        {
            int R=x+1, C=y+1, S=z+1;

            bool valid=true;
            int PR=0,PC=0,PS=0;
            rep(i,p)
            {
                int ex_indent=PR*R+PC*C+PS*S;
                if(ex_indent!=indent[i])
                {
                    valid=false;
                    break;
                }

                PR+=pr[i];
                PC+=pc[i];
                PS+=ps[i];
            }

            if(!valid) continue;

            int QR=0,QC=0,QS=0;
            rep(i,q)
            {
                int qq=QR*R+QC*C+QS*S;
                if(ans[i]==INF) ans[i]=qq;
                else if(ans[i]!=-1)
                {
                    if(ans[i]!=qq) ans[i]=-1;
                }

                QR+=qr[i];
                QC+=qc[i];
                QS+=qs[i];
            }
        }

        rep(i,q)
        {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
