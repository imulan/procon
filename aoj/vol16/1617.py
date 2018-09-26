def solve(s1,s2):
    if s1 == s2:
        return 0

    l1,l2 = s1.split('"'),s2.split('"')
    if len(l1) != len(l2):
        return 1

    ct = 0
    for i in range(len(l1)):
        if i%2 == 0:
            if l1[i] != l2[i]:
                return 1
        else:
            if l1[i] != l2[i]:
                ct += 1
            if ct > 1:
                return 1
    return 2

def main():
    ans = ['IDENTICAL', 'DIFFERENT', 'CLOSE']
    while True:
        s1 = input()
        if s1 == '.':
            return
        s2 = input()
        print(ans[solve(s1,s2)])

if __name__ == '__main__':
    main()
