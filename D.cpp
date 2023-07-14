#include <iostream>
using namespace std;
const int MAXN = 1000 + 10;
int n, data[MAXN];
int dp[MAXN]; 
int from[MAXN]; 
void output(int x)
{
	if(!x)return;
	output(from[x]);
	cout<<data[x]<<" ";
	//迭代输出 
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>data[i];
	
	// DP
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		from[i]=0;
		for(int j=1;j<i;j++)
		if(data[j]<data[i] && dp[i]<dp[j]+1)
		{
			dp[i]=dp[j]+1;
			from[i]=j;//逐个记录前驱 
		}
	}
	
	int ans=dp[1], pos=1;
	for(int i=1;i<=n;i++)
		if(ans<dp[i])
		{
			ans=dp[i];
			pos=i;//由于需要递归输出
	//所以要记录最长上升子序列的最后一
	//个元素，来不断回溯出路径来 
		}
	cout<<ans<<endl;
	output(pos);
	
	return 0;
}