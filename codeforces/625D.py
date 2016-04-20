
#n=int(input())

for n in range(1333):
    print("case",n)
    for a in range(n):
        p=str(a)
        q=p[::-1]
        ar=int(q)

        if a+ar==n:
            """
            print(n)
            break
            """
            print(a,ar)
