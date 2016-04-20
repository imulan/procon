n=int(input())
for t in range(n):
    s=input().split()
    s.reverse()

    print("Case #{0}:".format(t+1),end="")
    for v in s:
        print(" "+v,end="")
    print()
