#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,V;
struct Cup{
	int a,v;
	int id;
	friend bool operator<(Cup A,Cup B){
		return A.a>B.a;
	}
};Cup p[maxn];

bool cmpID(Cup A,Cup B){
	return A.id<B.id;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>V){
		for(int i=1;i<=n;i++) scanf("%d",&p[i].a),p[i].id=i;
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++){
			p[i].v=(p[i].a+1)/2;
			V-=p[i].v;
		}
		if(V<0){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(V<=0) break;
			int t=p[i].v;
			t+=min(V,p[i].a-p[i].v);
			V-=min(V,p[i].a-p[i].v);
			p[i].v=t;
		}
		if(V>0){
			puts("-1");continue;
		}
		sort(p+1,p+n+1,cmpID);
		for(int i=1;i<=n;i++) printf("%d ",p[i].v);puts("");
	}
	return 0;
}

