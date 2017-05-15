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
		int t=n,cnt=0;
		while(t) cnt++,t/=10;
		cnt--;
		t=1;
		while(cnt--) t*=10;
		printf("%d\n",-n%t+t);
	}
	return 0;
}
