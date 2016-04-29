/*先頭と最後尾が同じ単語が入ってきた時にどう処理するかが問題*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	while(1){
		int n;
		int head[26], tail[26], same[26]; //頭，尻，両方が同じ
		
		for(int i=0; i<26; ++i){
			head[i]=tail[i]=same[i]=0;	
		}
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			string s;
			cin >> s;
		
			if(s[0]==s[s.size()-1]) same[s[0]-'a']++;
			else{
				head[s[0]-'a']++;
				tail[s[s.size()-1]-'a']++;
			}
		}
		
		bool ans=true;
		for(int i=0; i<26; ++i){
			if(head[i] != tail[i]) ans=false;	
		}
		
		int ct=0;
		for(int i=0; i<26; ++i){
			if(same[i]>0) ct++;	
		}
		
		if(ans && ct==1){
			for(int i=0; i<26; ++i){
				if(same[i]>0){
					if(same[i]==n || head[i]>0 ){}
					else{
						ans=false;
						break;
					}
				}	
			}
		}
		else if(ans && ct>=2){
			for(int i=0; i<=26; ++i){
				if(same[i]>0){
					if(head[i]==0){
						ans=false;
						break;
					}	
				}	
			}
		}
		
		if(ans) printf("OK\n");
		else printf("NG\n");		
	}
}