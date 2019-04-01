D = 100000

# sum 1..x
def f(x):
    return x*(x+1)//2

def main():
    n = int(input())

    x = [1 for i in range(D)]
    x[0] = 0
    for i in range(3,D):
        x[i] += f(i-2)

    d,s = 0,0
    while s+x[d] < n:
        s += x[d]
        d += 1

    # print(s,d)
    b = [1 for i in range(d)]

    l = 1
    while l < d-1:
        if s + (d-1-l) >= n:
            break
        s += (d-1-l)
        l += 1

    # print(s,l)
    if l < d-1:
        r = d-2
        s += 1
        while r > l:
            if s == n:
                break
            s += 1
            r -= 1

        for i in range(l,r+1):
            b[i] = 0

    ans = 0
    for i in b:
        ans = ans*2 + i
    print(ans)

if __name__ == "__main__":
    main()
