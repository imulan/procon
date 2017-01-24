from collections import defaultdict

mod = 10**9+7;

def prime_factorize(n):
    primes = {}
    for i in range(2, int(n**0.5+1)):
        if n%i == 0:
            count = 0
            while n%i == 0:
                n //= i
                count += 1
            primes[i] = count
    if n > 1:
        primes[n] = 1

    return primes

def main():
    n = int(input())

    factors = defaultdict(int)

    for i in range(1, n+1):
        for k,v in  prime_factorize(i).items():
            factors[k] += v

    ans = 1
    for v in factors.values():
        ans *= v+1
        ans %= mod
    print(ans)

if __name__ == '__main__':
    main()
