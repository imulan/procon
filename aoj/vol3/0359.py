def main():
    w = ['fri','sat','sun','mon','tue','wed','thu']
    x = int(input()) - 1
    print(w[x%7])

if __name__ == '__main__':
    main()
