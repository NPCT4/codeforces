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
vector<int> S[maxn];
vector<ll> sum[maxn];
int dt[maxn][2];

pair<int,int> dfs(int u,int f){
	pair<int,int> res=make_pair(0,u);
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f) continue;
		pair<int,int> tmp=dfs(v,u);
		tmp.first++;
		res=max(res,tmp);
	}
	return res;
}

void dfs1(int u,int f,int op){
	dt[u][op]=0;
	if(f) dt[u][op]=dt[f][op]+1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==f) continue;
		dfs1(v,u,op);
	}
}

int get_D(int rt){
	int x=dfs(rt,0).second;
	pair<int,int> tmp=dfs(x,0);
	int y=tmp.second;
	dfs1(x,0,0);
	dfs1(y,0,1);
	return tmp.first;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool cmp(int a,int b){
	return d[a]>d[b];
}

void init(){
	for(int i=1;i<=n;i++){
		int rt=find(i);
		S[rt].push_back(i);
	}
	for(int rt=1;rt<=n;rt++){
		if(find(rt)==rt) D[rt]=get_D(rt);
	}
	for(int i=1;i<=n;i++) d[i]=max(dt[i][0],dt[i][1]);
	for(int i=1;i<=n;i++){
		if(find(i)==i){
			sort(S[i].begin(),S[i].end(),cmp);
			ll now=d[S[i][0]];
			sum[i].push_back(now);
			for(int j=1;j<S[i].size();j++)
				sum[i].push_back(sum[i][j-1]+d[S[i][j]]);
		}
	}
}

int bin(int l,int r,int x,int y,int u){
	int res=r+1;
	while(l<=r){
		int m=(l+r)>>1;
		int v=S[y][m];
		if(d[u]+d[v]+1<=max(D[x],D[y])) res=min(res,m),r=m-1;
		else l=m+1;
	}
	return res;
}

double work(int x,int y){
	ll Dt=max(D[x],D[y]);
	ll res=0;
	for(int i=0;i<S[x].size();i++){
		int u=S[x][i];
		int syn=(int)S[y].size();
		int c=bin(0,syn-1,x,y,u);
		ll L=0,R=0;
		if(c) L=1LL*c*(d[u]+1)+sum[y][c-1];
		R=1LL*(syn-c)*Dt;
		ll tmp=L+R;
		res+=tmp;
	}
	return 1.0*res/(1LL*cnt[x]*cnt[y]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m>>q){
		for(int i=1;i<=n;i++) G[i].clear(),fa[i]=i,S[i].clear(),cnt[i]=1;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			int x=find(u),y=find(v);
			if(x!=y) fa[x]=y,cnt[y]+=cnt[x],cnt[x]=0;
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
			if(cnt[x]>cnt[y]) swap(x,y);
			else if(cnt[x]==cnt[y]&&x>y) swap(x,y);
			if(vis[make_pair(x,y)]){
				int z=vis[make_pair(x,y)];
				printf("%.10f\n",ans[z]);
				continue;
			}
			vis[make_pair(x,y)]=vis[make_pair(y,x)]=++ansn;
			ans[ansn]=work(x,y);
			printf("%.10f\n",ans[ansn]);
		}
	}
	return 0;
}


