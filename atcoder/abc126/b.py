s = input()

a = 0
if 1 <= int(s[0:2]) <= 12:
    a += 1
if 1 <= int(s[2:]) <= 12:
    a += 2

print(["NA", "MMYY", "YYMM", "AMBIGUOUS"][a])
