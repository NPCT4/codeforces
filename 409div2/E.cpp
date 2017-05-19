#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,m;
int ban[maxn],x;
int ans[maxn],ansn;
vector<int> G[maxn];

void build(){

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m){
		for(int i=0;i<m;i++) ban[i]=0;
		for(int i=1;i<=n;i++) scanf("%d",&x),ban[x]=1;
		build();
		solve();
		printf("%d\n",ansn);
		for(int i=1;i<=ansn;i++) printf("%d ",ans[i]);puts("");
	}
	return 0;
}

