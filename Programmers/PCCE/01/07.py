num_list = [9, 2, 3, 1, 6, 8, 0, 8, 9, 2, 1, 7, 7, 3, 5]

count_list = [0] * 10

for i in range(len(num_list)):
    # count_list[i] += i
    count_list[num_list[i]] += 1

# 출력 코드
print(count_list)