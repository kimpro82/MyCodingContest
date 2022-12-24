def solution(text, anagram, sw):
    answer = ''
    temp = [[]] * len(text)                     # no [] but [[]]
    if sw == True:
        for i in range(len(text)):
            temp[anagram[i]] = text[i]
        for i in temp:
            answer += i
    else:
        for i in range(len(text)):
            answer += text[anagram[i]]
    return answer