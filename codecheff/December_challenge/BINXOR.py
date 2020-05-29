# from math import *
#
# def nCr(n, r):
#
#     # p holds the value of n*(n-1)*(n-2)...,
#     # k holds the value of r*(r-1)...
#     p = 1
#     k = 1
#
#     # C(n, r) == C(n, n-r),
#     # choosing the smaller value
#     if (n - r < r):
#         r = n - r
#
#     if (r != 0):
#         while (r):
#             p *= n
#             k *= r
#
#             # gcd of p, k
#             m = gcd(p, k)
#
#             # dividing by gcd, to simplify product
#             # division by their gcd saves from the overflow
#             p //= m
#             k //= m
#
#             n -= 1
#             r -= 1
#
#         # k should be simplified to 1
#         # as C(n, r) is a natural number
#         # (denominator should be 1 )
#
#     else:
#         p = 1
#
#     # if our approach is correct p = ans and k =1
#     return p
# def ans(a,b,n):
#     n=int(n)
#     na=int(0)
#     nb=int(0)
#     for i in a:
#         if i=='1':
#             na+=1
#     for i in b:
#         if i=='1':
#             nb+=1
#     nmin=abs(na-nb)
#     nmax=0
#     if(na+nb<=n):
#         nmax=na+nb
#     else:
#         nmax=2*n-na-nb
#     sum=int(0)
#     for k in range(nmin,nmax+1,2):
#         sum+=nCr(n,k)
#     return sum
#
# t=int(input())
# k=int(0)
# while(k<t):
#     n=int(input())
#     a=input()
#     b=input()
#     print(ans(a,b,n)%1000000007 )
#     k+=1
def f(i, a, b) :
    astr=str(a)
    N=len(astr)
    # a=int(a)
  # The rest must be 0's
    if a == 0 and b == 0:
        return 1

  # The rest must be 1's
    if (N - i) == a and (N - i) == b:
        return 1

  # P_a[i] must be 1
    if (N - i) == a:
            return 2 * (f(i+1, a-1, b-1) + f(i+1, a-1, b))

  # P_b[i] must be 1
    if (N - i) == b:
        return 2 * (f(i+1, a-1, b-1) + f(i+1, a, b-1))

  # General case
    return 2 * (
    f(i+1, a-1, b-1) +
    f(i+1, a-1, b) +
    f(i+1, a, b-1) +
    f(i+1, a, b)
    )
A=int("00")
B=int("01")
print(f(0, bin(A).count('1'), bin(B).count('1')))
