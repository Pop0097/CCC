# Score: 15/15

nums = [[1, 2], [3, 4]]
temp_nums = [[1, 2], [3, 4]];

# gets input
transformations = input();

# Applies transofmrations
for i in transformations:
    if i == "V": # reflection accross y axis
        nums[0][0] = temp_nums[0][1]
        nums[0][1] = temp_nums[0][0]
        nums[1][0] = temp_nums[1][1]
        nums[1][1] = temp_nums[1][0]
    else: # reflection accross x axis
        nums[0][0] = temp_nums[1][0]
        nums[0][1] = temp_nums[1][1]
        nums[1][0] = temp_nums[0][0]
        nums[1][1] = temp_nums[0][1]

    # sets temp array equal to main array
    temp_nums[0][0] = nums[0][0]
    temp_nums[0][1] = nums[0][1]
    temp_nums[1][0] = nums[1][0]
    temp_nums[1][1] = nums[1][1]


# displays answer
for i in range(2):
    print(str(nums[i][0]) + " " + str(nums[i][1]))