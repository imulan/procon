#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, r;
	string s;
	
	cin >> n >> r;
	cin >> s;
	
	int now=0; //現在イカのいる場所
	int ans=0;
	int dest=-1; //最終的な立ち位置
	
	bool e=false;
	//最終的な立ち位置の検索
	for(int i=0; i<s.size(); ++i){
		if(s[i]=='.') dest=i;	
	}
	
	if(dest==-1) e=true;
	
	dest=dest-r+1;
	if(dest<0) dest=0;
	//printf("dest=%d\n", dest);
	
	while(!e){
		if(now>=dest || s[now]=='.'){ //足場が塗られてなかったら塗る
			//printf("paint %d\n", now);
			int lim=now+r-1;
			if(lim>s.size()-1) lim=s.size()-1;
			
			for(int i=now; i<=lim; ++i) s[i]='o';
			
			ans++;
			
			//全て塗り終わったか判定
			bool end=true;
			for(int i=0; i<s.size(); ++i){
				if(s[i]=='.'){
					end=false;
					break;
				}
			}
			if(end) break;
			
		}		
		else{ //既に塗られてたら進む
			//cout << s << endl;
			//printf("go\n");
			now++;
			ans++;
		}
	
	}
	printf("%d\n", ans);	
}