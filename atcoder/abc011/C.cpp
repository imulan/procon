#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, ng[3];
	int count=0; //101になったらゲームオーバー
	bool ans=true;
	
	//入力
	cin >> n;
	for(int i=0 ;i<3; ++i){
		cin >> ng[i];
		if(n==ng[i]) ans=false;
	}
	sort(ng, ng+3);
	
	//シミュレーション
	while(ans && count<101 && n>0){
		
		//できるなら3を引く,無理なら2,1の順
		for(int i=3; i>0; --i){
			bool ok=true;
			for(int j=0; j<3; ++j) if(n-i == ng[j]) ok=false;
				
			if(ok){
				n -= i;	
				++count;
				break;
			}
			
			if(i==1) ans=false; //1,2,3どれでもダメだった
		}
		
		//printf("now n = %d\n", n);
	}
	
	if(count==101) ans=false;
	
	if(ans)printf("YES\n");
	else printf("NO\n");	
	return 0;
}