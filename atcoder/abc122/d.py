mod = 10**9 + 7
s = 'ACGT'
bad = ['AGC', 'ACG', 'GAC', 'ACGC', 'AGGC', 'ATGC', 'AGAC', 'AGGC', 'AGTC']

def valid(a):
    if a[0:3] in bad:
        return False
    if a[1:] in bad:
        return False
    if a in bad:
        return False
    return True

n = int(input())

dp = [[[1 for k in range(4)] for j in range(4)] for i in range(4)]
for i in range(4):
    for j in range(4):
        for k in range(4):
            t = s[k]+s[j]+s[i]
            if t in ['AGC', 'ACG', 'GAC']:
                dp[i][j][k] = 0

for pos in range(3,n):
    nx = [[[0 for k in range(4)] for j in range(4)] for i in range(4)]

    for i in range(4):
        for j in range(4):
            for k in range(4):
                for l in range(4):
                    t = s[k]+s[j]+s[i]+s[l]

                    if valid(t):
                        nx[l][i][j] += dp[i][j][k]
                        nx[l][i][j] %= mod
    dp = nx

ans = 0
for i in range(4):
    for j in range(4):
        for k in range(4):
            ans += dp[i][j][k]
            ans %= mod
print(ans)
