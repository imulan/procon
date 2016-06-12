#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rep1(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

bool a[10][10];

int main()
{
    while(true){
        char c;
        int H=0, W=0;
        bool flg=true;
        while(flg){
            int x=0;
            while(true){
                c=getchar();
                if(c=='#') return 0;

                if(c=='b'){
                    a[H][x]=true;
                    x++;
                } else if(c=='/'){
                    H++;
                    W=x;
                    break;
                } else if(c=='\n'){
                    H++;
                    flg=false;
                    break;
                } else {
                    int n=c-'0';
                    rep(i,n){
                        a[H][x+i]=false;
                    }
                    x+=n;
                }

            }
        }

        // b:true, .:false

        int x1,y1,x2,y2;
        scanf("%d %d %d %d\n", &y1,&x1,&y2,&x2);

        swap(a[y1-1][x1-1], a[y2-1][x2-1]);
/*
        a[y1-1][x1-1]=false;
        a[y2-1][x2-1]=true;
*/
        rep(y,H){
            int cnt=0;
            rep(x,W){
                if(a[y][x]){
                    if(cnt>0){
                        cout<<cnt;
                        cnt=0;
                    }
                    cout<<"b";
                }else{
                    cnt++;
                }
            }
            if(cnt>0)cout<<cnt;
            if(y!=H-1)cout<<"/";
        }
        cout<<endl;

    }

    return 0;
}
