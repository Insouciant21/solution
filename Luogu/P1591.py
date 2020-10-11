"""
  Problem: P1591
  Time: 2020/10/11 11:25:14
  Author: Insouciant21
  Status: Accepted
"""
t = int(input())
while t:
    t -= 1
    k, c = input().split()
    p = int(k)
    n = 1
    while p:
        n *= p
        p -= 1
    st = "%d" % n
    ans = 0
    for ch in st:
        if ch == c:
            ans += 1
    print(ans)
