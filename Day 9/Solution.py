from itertools import combinations


with open("input.txt") as f:
    nums = list(map(int,f.readlines()))
def part1(nums):
    for i in range(25, len(nums)):
        if all([x + y != nums[i] for x, y in combinations(nums[i-25:i],2)]):
            break
    return nums[i]

target = part1(nums)
def part2(nums,target):
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            if sum(nums[i:j]) == target:
                return min(nums[i:j]) + max(nums[i:j])

print(target)
print(part2(nums,target))