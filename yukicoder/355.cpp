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

typedef vector<int> vi;

int x,y;

void query(const vi &v)
{
    //クエリ生成
    rep(i,v.size())
    {
        if(i) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    cout << flush;
    //答え取得
    cin >>x >>y;
}


int main()
{
    bool end=false;

    //まず012を固定,3~9を調べる
    vi v1(4);
    rep(i,3) v1[i]=i;

    int s1[10]={0};
    for(int i=3; i<=9; ++i)
    {
        v1[3]=i;
        query(v1);

        if(x==4)
        {
            end=true;
            break;
        }

        s1[i]=x+y;
    }

    if(!end)
    {
        int large=0,small=4;
        for(int i=3; i<=9; ++i)
        {
            large=max(large,s1[i]);
            small=min(small,s1[i]);
        }

        //largeとsmallにグループ分け
        vi L,S;
        for(int i=3; i<=9; ++i)
        {
            if(s1[i]==large) L.pb(i);
            if(s1[i]==small) S.pb(i);
        }

        vi v2(4);
        //Sはハズレ数字の集合，最低でも3個はある
        rep(i,3) v2[i]=S[i];
        //その3つのハズレ数字を固定し，012の可能性を調べる
        rep(i,3)
        {
            v2[3]=i;
            query(v2);

            //答えにiは含まれている
            if(x+y==1) L.pb(i);
        }

        sort(all(L));

        do{
            query(L);
            if(x==4) break;
        }while(next_permutation(all(L)));
    }

    return 0;
}
