pi = '14159265358979323846264338327950'

def main():
    n = input()
    if n == '3':
        return 0
    return pi.find(n) + 1;

if __name__ == '__main__':
    print(main())
