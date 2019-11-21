N, W = map(int, input().split())
mv = 10 ** 5
INF = 10 ** 10
dp = [INF] * (mv + 1)
dp[0] = 0
ans = 0
for i in range(N):
    w, v = map(int, input().split())
    for j in range(mv, v-1, -1):
        dp[j] = min(dp[j], dp[j-v] + w)
        if dp[j] <= W:
            ans = max(ans, j)
print(ans)
