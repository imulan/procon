def main():
    op = '+-'
    s = input()

    for x in op:
        for y in op:
            for z in op:
                t = s[0] + x + s[1] + y + s[2] + z + s[3]
                if eval(t) == 7:
                    return t + '=7'

if __name__ == '__main__':
    print(main())
