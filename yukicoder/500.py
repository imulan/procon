MOD = 10**12

def fact(n):
    ret = 1
    for i in range(1,n+1):
        ret *= i
    return ret

def main():
    n = int(input())

    if n >= 50:
        return '000000000000'
    else:
        ret = str(fact(n)%MOD)
        if fact(n)>=MOD:
            while len(ret)<12:
                ret = '0'+ret
        return ret


if __name__ == '__main__':
    print(main())
