def solution(serial):
    answer = ''
    # serial = str(serial)                                                      # not needed

    # Elements
    sex      = ["male", "female"]
    division = ["operation", "sales", "develop", "finance", "law", "research"]

    if serial[4] != "0":
        team = serial[4:6] + "team"
    else :
        team = serial[5] + "team"

    sum = 0
    for i in serial[0:6]:
        sum += int(i)   
    valid    = ["invalid", "valid"]        

    # Concatenate
    answer += sex[int(serial[0:2])-1] + "/" + \
              division[int(serial[2:4])-10] + "/" + \
              team + "/" + \
              valid[sum % 13 == int(serial[6:])]

    return answer