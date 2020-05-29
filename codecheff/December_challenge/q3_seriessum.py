def series_sum(n):
    numerator= int(1)
    denominator=2
    sum=0
    while(numerator!=n):
        sum+=(numerator/denominator)
        numerator++
    return sum
n=int(input("(1/2 + 2/3 + 3/4 +.....n/(n+1) )Sum upto n. Enter n: "))
print("series sum:", series_sum(n))        
