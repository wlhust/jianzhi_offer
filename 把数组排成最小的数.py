def cmp(str1, str2):
    return 1 if int(str1+str2) > int(str2+str1) else -1
    
def PrintMinNumber(numbers):
    # write code here
    nums = [str(num) for num in numbers]
    nums.sort(cmp)
    print(nums)
    return int(''.join(nums))

numbers = [3,5,1,4,2]
print(PrintMinNumber(numbers))
