# BOJ / Lv 1 / Q 1000 / A plus B
# 2025/05/07

ptr0 , > ptr1 , > ptr2 , > ptr3 ,                           # Input A(ptr0) & B(ptr2) : 48(0) ~ 57(9)

> ptr4 +++++ +++++ ++
[ > ptr5 ++++ > ptr6 ++++ << ptr4 - ]                       # ptr5 & ptr6 = 12 * 4 = 48(0)

> ptr5 [ <<<<< ptr0 - >> ptr2 - >>> ptr5 - ]                # ptr0 & ptr2 - 48(0)

<<<<< ptr0 [ >>>>> >> ptr7 + > ptr8 + <<<<< <<< ptr0 - ]    # ptr7 & ptr8 = ptr0
>> ptr2 [ >>>>> ptr7 + > ptr8 + <<<<< < ptr2 - ]            # ptr7 & ptr8 = ptr0 plus ptr2

>>>> ptr6 [ > ptr7 + < ptr6 - ]                             # ptr7 plus 48(0)
> ptr7 .                                                    # Output ptr7 (available only when ptr7 lt 10
