def ham_to_num(s):
    ret=0
    sp = s.split('h')

    for i in range(1,len(sp)):
        if sp[i] == 'amu':
            ret = ret*2+1
        else:
            ret = ret*2

    return ret

def num_to_ham(num):
    s=''
    while True:
        if num%2==0:
            s = '0'+s
        else:
            s = '1'+s

        num = num//2
        if num == 0:
            break

    ret=''
    for c in s:
        if c == '0':
            ret = ret+'ham'
        else:
            ret = ret+'hamu'

    return ret

def solve(s):
    num = ham_to_num(s)
    print(num_to_ham(2*num))

if __name__ == '__main__':
    solve(input())
