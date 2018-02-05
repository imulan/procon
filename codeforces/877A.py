def main():
    s = input()
    S = len(s)

    ct = 0
    for f in ['Danil', 'Olya', 'Slava', 'Ann', 'Nikita']:
        F = len(f)
        for i in range(S-F+1):
            t = s[i:i+F]
            if f == t:
                ct += 1

    if ct == 1:
        return 'YES'
    return 'NO'

if __name__ == '__main__':
    print(main())
