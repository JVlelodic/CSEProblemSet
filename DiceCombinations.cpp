#include <iostream>
using namespace std;

int main(){
	int MOD = 1000000007;
	int n;
	cin >> n;
			
	long long *dp = new long long[n+1];	
	dp[0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 6; j++){
			if(i - j < 0 ) break;
			dp[i] += dp[i-j];
			dp[i] %= MOD;
		}
	}
	cout << dp[n] << "\n";
}
