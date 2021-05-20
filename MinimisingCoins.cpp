#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int x;
	cin >> x;
	
	int *coins = new int[n];
	for(int i = 0; i < n; i++) cin >> coins[i];
	sort(coins, coins + n);

	int *dp = new int[x+1];
	dp[0] = 0;

	for(int i = 1; i <= x; i++){
		dp[i] = INT_MAX;
		for(int j = 0; j < n; j++){
			if(i - coins[j] < 0) break;
			int prev = dp[i-coins[j]];
			int newMin = prev == INT_MAX ? INT_MAX : prev + 1;
			dp[i] = min(dp[i], newMin);
		}
	}
	int ret = dp[x] == INT_MAX ? -1 : dp[x];
	cout << ret;
}

