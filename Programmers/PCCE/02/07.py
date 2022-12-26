def func1(msg):
    return len(msg)

def func2(msg):
    for letter in msg:
        if '0' <= letter <= '9':
            continue
        return False
    return True

def func3(msg):
    for letter in msg:
        if 'a' <= letter <= 'z':
            return True
        if 'A' <= letter <= 'Z':
            return True
    return False

def func4(msg):
    while(" " in msg):
        msg = msg.replace(" ", "")
    return msg

def func5(msg):
    return msg[:3] + "-" + msg[3:7] + "-" + msg[7:]

def solution(phone):
    phone = func4(phone)

    if not func2(phone) :
        return "잘못된 입력입니다"

    if func1(phone) != 11:
        return "잘못된 입력입니다"

    phone = func5(phone)

    return phone