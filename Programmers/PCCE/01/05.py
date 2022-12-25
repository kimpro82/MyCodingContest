def func1(a):
    return a * a

def func2(a):
    if a < 0 :
        return -1 * a
    return a

def func3(a, b):
    return a - b

def func4(a, b):
    if b > 0:
        return a % b
    return a % (-1 * b)


num1 = int(input())
num2 = int(input())

answer_mod = func4(num1, num2)
answer_pow = func1(num1)
answer_abs = func2(num2)

print("num1을 num2의 절댓값으로 나눈 나머지는", answer_mod, "입니다")
print("num1의 제곱 값은", answer_pow, "입니다")
print("num2의 절댓값은", answer_abs, "입니다")