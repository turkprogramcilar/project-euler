x = [1,2,1]
binomal = {1,2}
for i in range(48):
    temp = [1]
    for j in range(len(x)-1):
        temp.append(x[j] + x[j+1])
        binomal.add(x[j] + x[j+1])
    temp.append(1)
    x = temp

def is_sq_free(x):
    for prime in [4,9,25,49]:
        if x % prime == 0:
            return False
    return True

print(sum(x for x in binomal if is_sq_free(x)))
