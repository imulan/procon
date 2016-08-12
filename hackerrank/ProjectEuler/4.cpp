#include <cstdio>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

bool isPalindromic(long a){
	stringstream ss;
	ss<<a;
	
	string s=ss.str();
	bool ret=true;
	
	for(int i=0; i<s.size(); ++i){
		if(s[i] != s[s.size()-1-i]) ret=false;	
	}
	
	return ret;
}

int main(){
	set<long> p;
	
	for(long i=999; i>=100; --i){
		for(long j=i; i*j>=100000; --j){
			if(isPalindromic(i*j)){	
				p.insert(i*j);	
			}
		}
	}
	
	int t;
	scanf(" %d", &t);
	for(int i=0; i<t; ++i){
		long n;
		scanf(" %ld", &n);
		
		for(set<long>::iterator it=p.begin(); it!=p.end(); ++it){
			if(*it>n){
				it--;
				cout << *it << endl;
				break;
			}
		}
	}
}