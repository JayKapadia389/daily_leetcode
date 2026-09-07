class Solution {
    public int distinctSubseqII(String s) {
        int[] dp = new int[26];
        int total = 0, n = s.length();
        int MOD = 1000000007;

        for(int i = 0; i < n; ++i) {
            long prev_total = total;
            char curr_ch = s.charAt(i);
            total = (int)((2 * prev_total + 1 - dp[curr_ch - 'a'] + MOD) % MOD);
            dp[curr_ch - 'a'] = (int) (prev_total + 1) % MOD;
        }

        return total;
    }
}