n,m = map(int,input().split())

mn = max(0,n-2*m)

mx = 0
for i in range(n):
    if i*(i-1)//2 >= m:
        mx = n-i
        break

print(mn,mx)
