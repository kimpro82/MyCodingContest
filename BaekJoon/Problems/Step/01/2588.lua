-- 2588. 곱셈
-- 2025.12.27

a, b = io.read("*n", "*n")

ans1 = a * (b % 10)
ans2 = a * (math.floor((b % 100) / 10))
ans3 = a * math.floor(b / 100)
ans4 = a * b

print(ans1)
print(ans2)
print(ans3)
print(ans4)
