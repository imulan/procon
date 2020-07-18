from collections import defaultdict

d = defaultdict(int)
for i in range(int(input())):
    d[input()] += 1

for i in ['AC', 'WA', 'TLE', 'RE']:
    print(i+' x', d[i])
