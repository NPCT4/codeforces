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
		if(n&1) printf("%d\n",n/2);
		else printf("%d\n",n/2-1);
	}
	return 0;
}


