def check(s):
    return s[0]==s[1]==s[2]

def main():
    n = input()
    for i in range(2):
        if check(n[i:i+3]):
            return 'Yes'
    return 'No'

if __name__ == '__main__':
    print(main())
