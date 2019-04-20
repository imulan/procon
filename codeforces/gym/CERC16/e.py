import collections

def main():
    k,n = map(int,input().split())

    used = set()
    vis = set()
    que = collections.deque()
    que.append((0,1,k))
    vis.add((0,1,k))

    ans = []
    while que:
        a,b,c = que.popleft()
        # print('now: ',a,b,c)

        for _ in range(3):
            aa = k*(b+c)-a

            # print( ' ',a,b,c,'->',aa,b,c)
            if aa!=b and b!=c and c!=aa and aa>0 and b>0 and c>0:
                if aa not in used and b not in used and c not in used:
                    used.add(aa)
                    used.add(b)
                    used.add(c)
                    ans.append((aa,b,c))

                    if len(ans) == n:
                        break

                if (aa,b,c) not in vis:
                    vis.add((aa,b,c))
                    que.append((aa,b,c))

            b,c,a = a,b,c

        if len(ans) == n:
            break

    for a,b,c in ans:
        print(a,b,c)


if __name__ == '__main__':
    main()
