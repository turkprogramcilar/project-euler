#mehmet_mert__ 
first_num = 999
second_num = 999
high_score = 0

def reverse_slicing(s):
    return s[::-1]

while True:
    if str(first_num*second_num) == reverse_slicing(str(first_num*second_num)):
        if first_num*second_num > high_score:
            high_score = first_num*second_num
            print(first_num, "x", second_num)
            print(high_score)
        second_num -= 1
    else:
        second_num -= 1
        if second_num < 100:
            first_num -= 1
            second_num = 999
        if first_num < 100:
            print("end")
            break


