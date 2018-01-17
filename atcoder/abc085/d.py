def main():
    n,h = map(int,input().split())
    a,b = [],[]
    for i in range(n):
        x,y = map(int,input().split())
        a.append(x)
        b.append(y)

    max_a = max(a)
    b.sort()
    b.reverse()

    now = 0
    ans = 0
    for i in range(n):
        now += max(b[i],max_a)
        ans += 1
        if now>=h:
            return ans

    rem = h-now
    ans += (rem+max_a-1)//max_a
    return ans

if __name__ == '__main__':
    print(main())
