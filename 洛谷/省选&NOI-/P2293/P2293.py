/* 
*  Problem: P2293
*  Author: Insouciant21
*  Status: Accepted
*/
a = int(input())
b = int(input())
p: int = 0
q: int = 1
while pow(q, a) <= b:
    p = q
    q = q * 2
while p + 1 < q:
    mid = (p + q) // 2
    if pow(mid, a) <= b:
        p = mid
    else:
        q = mid
if pow(p, a) <= b:
    print(p)
else:
    print(q)
