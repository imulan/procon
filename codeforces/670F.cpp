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


int main()
{
    string s,t;
    cin >>s >>t;

    //答えが0になる場合のみ排除
    if(s=="01" || s=="10")
    {
        printf("0\n");
        return 0;
    }

    int S=s.size();

    //各数字が何個あるかカウント
    vector<int> ct(10,0);
    rep(i,S) ++ct[s[i]-'0'];

    //10のi乗
    int p10[7];
    p10[0]=1;
    for(int i=1; i<=6; ++i) p10[i]=10*p10[i-1];

    //tに含まれる文字を予め除いておく
    rep(i,t.size()) --ct[t[i]-'0'];

    string ans="#";

    for(int x=1; x<=6; ++x)
    {
        int d=S-x;
        if(p10[x-1]<=d && d<=p10[x]-1)
        {
            vector<int> tct(ct);
            //桁数として使われる数を除く
            int td=d;
            while(td>0)
            {
                --tct[td%10];
                td/=10;
            }

            //このような構成は不可能
            rep(i,10)
            {
                if(tct[i]<0) continue;
            }

            string tmp="";

            //残った0以外の数の中で最小のもの
            int h1=1;
            while(h1<10 && tct[h1]==0) ++h1;

            //tの先頭
            int h2=t[0]-'0';

            //tが絶対先頭に来る場合
            if(h2!=0 && h2<h1)
            {
                tmp+=t;
                rep(i,10)rep(j,tct[i]) tmp+=i+'0';
            }
            else
            {
                string t1="", t2="", t3="";

                //t1の構成
                if(t[0]!='0')
                {
                    t1+=t;
                    rep(i,10)rep(j,tct[i]) t1+=i+'0';
                }

                //t2とt3の構成
                if(h1<10)
                {
                    t2+=h1+'0';
                    t3+=h1+'0';
                    --tct[h1];

                    for(int i=0; i<h2; ++i)rep(j,tct[i])
                    {
                        t2+=i+'0';
                        t3+=i+'0';
                    }

                    t2+=t;
                    rep(i,tct[h2]) t2+=h2+'0';

                    rep(i,tct[h2]) t3+=h2+'0';
                    t3+=t;

                    for(int i=h2+1; i<10; ++i)rep(j,tct[i])
                    {
                        t2+=i+'0';
                        t3+=i+'0';
                    }
                }

                //3つの中で最小値を選ぶ
                if(t1!="") tmp=t1;
                if(t2!="")
                {
                    if(tmp=="") tmp=t2;
                    else tmp=min(tmp,t2);
                }
                if(t3!="")
                {
                    if(tmp=="") tmp=t3;
                    else tmp=min(tmp,t3);
                }
            }

            //最小値を更新
            if(ans=="#") ans=tmp;
            else
            {
                if(ans.size()>tmp.size()) ans=tmp;
                else if(ans.size()==tmp.size()) ans=min(ans,tmp);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
