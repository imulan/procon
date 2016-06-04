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

bool num(char c)
{
    return ('0'<=c && c<='9');
}

ll ab(ll x)
{
    return (x>0?x:-x);
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        string C,J;
        cin >>C >>J;

        ll dif=999999999999999999;
        string x="#",y="#";

        int n=C.size();

        rep(i,n)
        {
            if(num(C[i]) && num(J[i]))
            {
                if(C[i]<J[i])
                {
                    //Jが大きいことが確定
                    rep(j,n) if(C[j]=='?') C[j]='9';
                    rep(j,n) if(J[j]=='?') J[j]='0';

                    //更新
                    ll a=atoll(C.c_str());
                    ll b=atoll(J.c_str());
                    if(ab(a-b)<dif)
                    {
                        x=C;
                        y=J;
                        dif=ab(a-b);
                    }
                    else if(ab(a-b)==dif)
                    {
                        if(x=="#")
                        {
                            x=C;
                            y=J;
                        }
                        else
                        {
                            if(C<x || (C==x&&J<y))
                            {
                                x=C;
                                y=J;
                            }
                        }
                    }
                }
                else if(C[i]>J[i])
                {
                    //Cが大きいことが確定
                    rep(j,n) if(C[j]=='?') C[j]='0';
                    rep(j,n) if(J[j]=='?') J[j]='9';

                    //更新
                    ll a=atoll(C.c_str());
                    ll b=atoll(J.c_str());
                    if(ab(a-b)<dif)
                    {
                        x=C;
                        y=J;
                        dif=ab(a-b);
                    }
                    else if(ab(a-b)==dif)
                    {
                        if(x=="#")
                        {
                            x=C;
                            y=J;
                        }
                        else
                        {
                            if(C<x || (C==x&&J<y))
                            {
                                x=C;
                                y=J;
                            }
                        }
                    }
                }
            }
            else if(num(C[i]))
            {
                if(C[i]!='9')
                {
                    string tc=C, tj=J;
                    tj[i]=C[i]+1;

                    //tjが大きいことが確定
                    rep(j,n) if(tc[j]=='?') tc[j]='9';
                    rep(j,n) if(tj[j]=='?') tj[j]='0';

                    //更新
                    ll a=atoll(tc.c_str());
                    ll b=atoll(tj.c_str());
                    if(ab(a-b)<dif)
                    {
                        x=tc;
                        y=tj;
                        dif=ab(a-b);
                    }
                    else if(ab(a-b)==dif)
                    {
                        if(x=="#")
                        {
                            x=tc;
                            y=tj;
                        }
                        else
                        {
                            if(tc<x || (tc==x&&tj<y))
                            {
                                x=tc;
                                y=tj;
                            }
                        }
                    }
                }
                if(C[i]!='0')
                {
                    string tc=C, tj=J;
                    tj[i]=C[i]-1;

                    //tcが大きいことが確定
                    rep(j,n) if(tc[j]=='?') tc[j]='0';
                    rep(j,n) if(tj[j]=='?') tj[j]='9';

                    //更新
                    ll a=atoll(tc.c_str());
                    ll b=atoll(tj.c_str());
                    if(ab(a-b)<dif)
                    {
                        x=tc;
                        y=tj;
                        dif=ab(a-b);
                    }
                    else if(ab(a-b)==dif)
                    {
                        if(x=="#")
                        {
                            x=tc;
                            y=tj;
                        }
                        else
                        {
                            if(tc<x || (tc==x&&tj<y))
                            {
                                x=tc;
                                y=tj;
                            }
                        }
                    }
                }

                J[i]=C[i];
            }
            else if(num(J[i]))
            {
                if(J[i]!='9')
                {
                    string tc=C, tj=J;
                    tc[i]=J[i]+1;

                    //tcが大きいことが確定
                    rep(j,n) if(tc[j]=='?') tc[j]='0';
                    rep(j,n) if(tj[j]=='?') tj[j]='9';

                    //更新
                    ll a=atoll(tc.c_str());
                    ll b=atoll(tj.c_str());
                    if(ab(a-b)<dif)
                    {
                        x=tc;
                        y=tj;
                        dif=ab(a-b);
                    }
                    else if(ab(a-b)==dif)
                    {
                        if(x=="#")
                        {
                            x=tc;
                            y=tj;
                        }
                        else
                        {
                            if(tc<x || (tc==x&&tj<y))
                            {
                                x=tc;
                                y=tj;
                            }
                        }
                    }
                }
                if(J[i]!='0')
                {
                    string tc=C, tj=J;
                    tc[i]=J[i]-1;

                    //tjが大きいことが確定
                    rep(j,n) if(tc[j]=='?') tc[j]='9';
                    rep(j,n) if(tj[j]=='?') tj[j]='0';

                    //更新
                    ll a=atoll(tc.c_str());
                    ll b=atoll(tj.c_str());
                    if(ab(a-b)<dif)
                    {
                        x=tc;
                        y=tj;
                        dif=ab(a-b);
                    }
                    else if(ab(a-b)==dif)
                    {
                        if(x=="#")
                        {
                            x=tc;
                            y=tj;
                        }
                        else
                        {
                            if(tc<x || (tc==x&&tj<y))
                            {
                                x=tc;
                                y=tj;
                            }
                        }
                    }

                }

                C[i]=J[i];
            }
            else
            {
                string tc,tj;

                //(0,1)を試す
                tc=C;
                tj=J;
                tc[i]='0';
                tj[i]='1';
                //tjが大きいことが確定
                rep(j,n) if(tc[j]=='?') tc[j]='9';
                rep(j,n) if(tj[j]=='?') tj[j]='0';

                //更新
                ll a=atoll(tc.c_str());
                ll b=atoll(tj.c_str());
                if(ab(a-b)<dif)
                {
                    x=tc;
                    y=tj;
                    dif=ab(a-b);
                }
                else if(ab(a-b)==dif)
                {
                    if(x=="#")
                    {
                        x=tc;
                        y=tj;
                    }
                    else
                    {
                        if(tc<x || (tc==x&&tj<y))
                        {
                            x=tc;
                            y=tj;
                        }
                    }
                }

                //(1,0)を試す
                tc=C;
                tj=J;
                tc[i]='1';
                tj[i]='0';
                //tcが大きいことが確定
                rep(j,n) if(tc[j]=='?') tc[j]='0';
                rep(j,n) if(tj[j]=='?') tj[j]='9';

                //更新
                a=atoll(tc.c_str());
                b=atoll(tj.c_str());
                if(ab(a-b)<dif)
                {
                    x=tc;
                    y=tj;
                    dif=ab(a-b);
                }
                else if(ab(a-b)==dif)
                {
                    if(x=="#")
                    {
                        x=tc;
                        y=tj;
                    }
                    else
                    {
                        if(tc<x || (tc==x&&tj<y))
                        {
                            x=tc;
                            y=tj;
                        }
                    }
                }

                C[i]=J[i]='0';
            }
        }

        //最後に更新
        ll a=atoll(C.c_str());
        ll b=atoll(J.c_str());
        if(ab(a-b)<dif)
        {
            x=C;
            y=J;
            dif=ab(a-b);
        }
        else if(ab(a-b)==dif)
        {
            if(x=="#")
            {
                x=C;
                y=J;
            }
            else
            {
                if(C<x || (C==x&&J<y))
                {
                    x=C;
                    y=J;
                }
            }
        }

        printf("Case #%d:", t+1);
        cout <<" "<<x<<" "<<y<<endl;
    }
    return 0;
}
