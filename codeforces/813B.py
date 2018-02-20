def main():
    x,y,l,r = map(int,input().split())

    unlucky = set()
    unlucky.add(l-1)
    unlucky.add(r+1)
    for i in range(70):
        X = x**i
        if X > r:
            break
        for j in range(70):
            Y = y**j
            u = X+Y
            if l <= u <= r:
                unlucky.add(u)

    lu = sorted(list(unlucky))
    ans = 0
    for i in range(len(lu)-1):
        ans = max(ans, lu[i+1]-lu[i]-1)

    return ans

if __name__ == '__main__':
    print(main())
