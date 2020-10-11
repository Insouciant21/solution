"""
  Problem: P1045
  Time: 2020/10/11 10:55:56
  Author: Insouciant21
  Status: Accepted
"""
import math

p = int(input())
print(int(math.log10(2) * p + 1))
m = 1
for i in range(0, 500):
    m *= 10
res = pow(2, p, m)
res -= 1
ans = '%0500d' % res
k = 0
for i in range(10):
    for j in range(50):
        print(ans[k], end='')
        k += 1
    print("")