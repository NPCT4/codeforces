#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n){
		for(int i=1;i<=n;i++){
			if(i%4==1||i%4==2) printf("a");
			else printf("b");
		}
		puts("");
	}
	return 0;
}

