def solution(year):
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return "윤년"
            else:
                return "평년"
        else:
            return "윤년"
    else:
        return "평년"