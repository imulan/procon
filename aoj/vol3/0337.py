def solve(e,y):
    if e == 0:
        if y < 1912:
            r = 'M' + str(y-1868+1)
        elif y < 1926:
            r = 'T' + str(y-1912+1)
        elif y < 1989:
            r = 'S' + str(y-1926+1)
        else:
            r = 'H' + str(y-1989+1)
    else:
        yy = [0,1868,1912,1926,1989]
        r = yy[e] + y - 1

    return r

def main():
    E,Y = map(int,input().split())
    print(solve(E,Y))

if __name__ == '__main__':
    main()
