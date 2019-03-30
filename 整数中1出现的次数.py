def NumberOf1Between1AndN_Solution(n):
    # write code here
    s = str(n)
    nums = [int(s_) for s_ in s]
    count = 0
    for i, num in enumerate(nums):
        a = n / (10**(len(nums) - 1 - i))
        b = n % (10**(len(nums) - 1 - i))
        if num == 0:
            count += a / 10 * 10**(len(nums) - 1 - i)
        elif num == 1:
            count += a / 10 * 10**(len(nums) - 1 - i) + b + 1
        else:
            count += (a / 10 + 1) * 10**(len(nums) - 1 - i)
    return count

if __name__ == "__main__":
    n = 12
    print(NumberOf1Between1AndN_Solution(n))
