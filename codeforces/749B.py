def main():
    x = [0 for _ in range(3)]
    y = [0 for _ in range(3)]

    for i in range(3):
        x[i],y[i] = map(int,input().split())

    print(3)
    for i in range(3):
        dx = x[(i+1)%3] - x[i]
        dy = y[(i+1)%3] - y[i]

        X = x[(i+2)%3]+dx
        Y = y[(i+2)%3]+dy

        print('{0} {1}'.format(X,Y))

if __name__ == '__main__':
    main()
