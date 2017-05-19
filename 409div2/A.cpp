#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

char s[maxn];
int vis[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(~scanf("%s",s)){
		int len=strlen(s);
		memset(vis,0,sizeof(vis));
		int res=0;
		for(int i=0;i+1<len;i++){
			if(s[i]=='V'&&s[i+1]=='K'){
				vis[i]=vis[i+1]=1;
				res++;
			}
		}
		int change=0;
		for(int i=0;i+1<len;i++){
			if(vis[i]||vis[i+1]) continue;
			if(s[i]=='V'){
				if(s[i+1]=='K') res++,i++;
				else if(change==0) change=1,res++,i++;
			}
			else{
				if(s[i+1]=='K') if(change==0) change=1,res++,i++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
