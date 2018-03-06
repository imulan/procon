def dist(p,q):
    return abs(p[0]-q[0]) + abs(p[1]-q[1])

def main():
    H,W,D = map(int,input().split())

    A = []
    for i in range(H):
        A.append(list(map(int,input().split())))

    pos = [(-1,-1) for i in range(H*W)]
    for i in range(H):
        for j in range(W):
            A[i][j] -= 1
            pos[A[i][j]] = (i,j)


    pre = [[0 for j in range((2*H*W)//D)  ] for i in range(D)]
    for i in range(D,H*W):
        pre[i%D][i//D] = pre[i%D][i//D - 1] + dist(pos[i], pos[i-D])

    Q = int(input())
    for _ in range(Q):
        L,R = map(int,input().split())
        L -= 1
        R -= 1

        v = pre[L%D]
        print(v[R//D] - v[L//D])

if __name__ == '__main__':
    main()
