n,k = map(int,input().split())
s = input()

for i in range(n):
    c = s[i]
    if i == k-1:
        c = c.lower()
    print(c, end="")
print()
