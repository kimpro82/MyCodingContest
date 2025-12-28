-- 10430. 나머지
-- 2025.12.27

a, b, c = io.read("*n", "*n", "*n")

ans1 = (a + b) % c
ans2 = ((a % c) + (b % c)) % c
ans3 = (a * b) % c
ans4 = ((a % c) * (b % c)) % c

print(ans1)
print(ans2)
print(ans3)
print(ans4)
