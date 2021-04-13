#mehmet_mert__0120 
result = 0

def fib(n):
    global result
    a, b = 0, 1
    while a < n:
        if a % 2 == 0:
            result += a
        a, b = b, a+b
    print()
fib(4000000)

print("result: ", result)

