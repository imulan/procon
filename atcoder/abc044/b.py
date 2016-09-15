ct = {}
for w in input():
    if w not in ct:
        ct[w] = 0
    ct[w] += 1

ans = "Yes"
for k,v in ct.items():
    if v%2 == 1:
        ans = "No"
print(ans)
