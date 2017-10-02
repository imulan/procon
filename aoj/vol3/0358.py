def main():
    m,f,b = map(int,input().split())

    if m+f < b:
        return 'NA'
    return max(0,b-m)

if __name__ == '__main__':
    print(main())
