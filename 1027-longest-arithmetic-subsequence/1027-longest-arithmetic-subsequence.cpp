class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
   int n = A.size();
	assert(n>=1 && n<=1000);
	if (n < 3) return n;
	vector<vector<int> > dp(n, vector<int>(n, -1));
	map<int, int> pos;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dp[i][j] = 2;
			int dif = A[j] - A[i];
			int need = 2 * A[i] - A[j];
			if (pos.count(need) == 0) continue;
			dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);
		}

		pos[A[i]] = i;
	}

	int ans = 2;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	return ans;
    }
};