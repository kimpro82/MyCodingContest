def crossBridge(steps):
    cnt = 0
    current = 0
    n = len(steps)
    while (current < n) :
        current += steps[current]
        cnt += 1

        # test
        # print(cnt, current)

    return cnt

print(crossBridge([1, 1, 2, 3, 5]))