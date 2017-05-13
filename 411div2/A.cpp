#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int l,r;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>l>>r){
		if(r-l>=2) puts("2");
		else printf("%d\n",l);
	}
	return 0;
}
