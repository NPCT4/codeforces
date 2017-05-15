#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,k;
int a[maxn];ll s[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>k){
		s[0]=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		ll res=0;
		for(int i=1;i<=n-k+1;i++) res+=s[i+k-1]-s[i-1];
		printf("%.10f\n",1.0*res/(n-k+1));
	}
	return 0;
}


