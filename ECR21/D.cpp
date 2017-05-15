#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,a[maxn];
ll s[maxn];

bool binL(int l,int r,int ax){
	while(l<=r){
		int m=(l+r)>>1;
		ll ls=s[m]+ax,rs=s[n]-s[m]-ax;
		if(ls==rs) return 1;
		if(ls<rs) l=m+1;
		else r=m-1;
	}
	return 0;
}

bool binR(int l,int r,int ax){
	while(l<=r){
		int m=(l+r)>>1;
		ll ls=s[m]-ax,rs=s[n]-s[m]+ax;
		if(ls==rs) return 1;
		if(ls<rs) l=m+1;
		else r=m-1;
	}
	return 0;
}

bool work(int x){
	bool tagL=binL(1,x-1,a[x]);
	bool tagR=binR(x+1,n,a[x]);
	return tagL||tagR;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n){
		s[0]=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(work(i)){
				flag=1;break;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}


