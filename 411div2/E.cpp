#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,m;
vector<int> S[maxn];
vector<int> G[maxn];
int k,x;
int u,v;
int cn,c[maxn];
set<int> color;

void dfs(int u,int f){
	color.clear();
	for(int i=0;i<S[u].size();i++){
		int t=S[u][i];
		if(c[t]) color.insert(c[t]);
	}
	int now=0;
	for(int i=0;i<S[u].size();i++){
		int t=S[u][i];
		if(c[t]) continue;
		++now;
		while(color.find(now)!=color.end()) ++now;
		c[t]=now;
		color.insert(now);
	}
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f) continue;
		dfs(v,u);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) S[i].clear(),G[i].clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			while(k--){
				scanf("%d",&x);
				S[i].push_back(x);
			}
			sort(S[i].begin(),S[i].end());
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=m;i++) c[i]=0;
		cn=0;
		dfs(1,0);
		for(int i=1;i<=m;i++){
			if(!c[i]) c[i]=1;
			cn=max(cn,c[i]);
		}
		cout<<cn<<endl;
		for(int i=1;i<=m;i++) printf("%d ",c[i]);puts("");
	}
	return 0;
}


