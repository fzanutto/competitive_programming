from collections import Counter

n = int(input())

l = [int(i) for i in input().split()]


num = Counter(l)

dp = [0] * (100001)

dp[1] = num[1]

for i in range(2,100001):
    dp[i] = max(dp[i-1], dp[i-2] + i*num.get(i, 0))

print(dp[100000])
