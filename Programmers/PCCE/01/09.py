def solution(num_list):
    answer = []
    for i in num_list:
        temp = True
        for j in range(2, int(i/2) + 1):
            if i % j == 0:
                temp = False
                break
        answer.append(temp)
    return answer