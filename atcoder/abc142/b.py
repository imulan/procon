def main():
    n,k = map(int,input().split())
    h = list(map(int,input().split()))
    print(len(list(filter(lambda x: x>=k, h))))

if __name__ == "__main__":
    main()
