N = 100010

p = [True for i in range(N)]
p[0]=p[1]=False
for i in range(2,N):
    if p[i]:
        for j in range(2*i,N,i):
            p[j] = False

s = [0 for i in range(N)]
for i in range(1,N,2):
    if p[i] and p[(i+1)//2]:
        s[i] = 1

for i in range(N-1):
    s[i+1] += s[i]

Q = int(input())
for _ in range(Q):
    l,r = map(int,input().split())
    print(s[r]-s[l-1])
