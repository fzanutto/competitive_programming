N, W = map(int, input().split())
max_value = 10 ** 5
INF = 10 ** 10
dp = [INF] * (max_value + 1)
dp[0] = 0
ans = 0
for i in range(N):
    w, v = map(int, input().split())
    for j in range(max_value, v-1, -1):
        dp[j] = min(dp[j], dp[j-v] + w)
        if dp[j] <= W:
            ans = max(ans, j)
print(ans)
