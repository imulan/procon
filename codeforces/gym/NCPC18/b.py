def main():
    n = int(input())
    l = list(input().split())
    for i in range(n):
        if l[i] == 'mumble':
            continue
        if int(l[i]) != i+1:
            return 'something is fishy'

    return 'makes sense'

if __name__ == "__main__":
    print(main())
