def main():
    a,b = map(int,input().split())

    if a == b:
        return 'Draw'

    if a == 1:
        return 'Alice'
    if b == 1:
        return 'Bob'

    return 'Alice' if a>b else 'Bob'

if __name__ == '__main__':
    print(main())
