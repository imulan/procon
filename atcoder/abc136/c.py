def solve():
    n = int(input())
    h = list(map(int,input().split()))

    h[0] -= 1
    for i in range(1,n):
        if h[i-1]<h[i]:
            h[i] -= 1
        if h[i-1]>h[i]:
            return 'No'
    return 'Yes'

if __name__ == "__main__":
    print(solve())
