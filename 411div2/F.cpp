#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,m,q;
int u,v;
vector<int> G[maxn];
int d[maxn];
int D[maxn],cnt[maxn],fa[maxn];
map<pair<int,int>,int> vis;
double ans[maxn];int ansn;



int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m>>q){
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		init();
		vis.clear();ansn=0;
		for(int i=1;i<=q;i++){
			scanf("%d%d",&u,&v);
			int x=find(u),y=find(v);
			if(x==y){
				puts("-1");
				continue;
			}
			if(cnt[u]>cnt[v]) swap(u,v);
			else if(cnt[u]==cnt[v]&&u>v) swap(u,v);
			if(vis[make_pair(u,v)]){
				int z=vis[make_pair(u,v)];
				printf("%.10f\n",ans[z]);
				continue;
			}
			vis[make_pair(u,v)]=++ansn;
			ans[ansn]=work(u,v);
			printf("%.10f\n",ans[ansn]);
		}
	}
	return 0;
}


