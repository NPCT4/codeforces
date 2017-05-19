#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

char x[maxn],y[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(~scanf("%s%s",x,y)){
		int n=strlen(x);
		bool flag=1;
		for(int i=0;i<n;i++){
			if(x[i]<y[i]){
				flag=0;break;
			}
		}
		puts(flag?y:"-1");
	}
	return 0;
}

