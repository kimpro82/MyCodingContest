# BOJ / Lv 1 / Q 2557 / Hello World
# 2025/04/21

ptr0 +++++                          # ptr0 = 5
[
  > ptr1 +++++ +++++ +++            # ptr1 = 13 * 5 = A(65)
  > ptr2 +++++ +++++ +++++ +++++    # ptr2 = 20 * 5 = d(100)
  > ptr3 ++++                       # ptr3 =  4 * 5 = space(32)
  > ptr4 +++++ +                    # ptr4 =  6 * 5 = (30)
  > ptr5 ++                         # ptr5 =  2 * 5 = LF(10)
  <<<<< ptr0 -
]
>> ptr2 ---                         # ptr2 = a(97)
>> ptr4 +++                         # ptr4 = !(23)
<<<< ptr0

> ptr1 +++++ ++ .                   # H
> ptr2 ++++ .                       # e
  ptr2 +++++ ++ ..                  # ll
  ptr2 +++ .                        # o

> ptr3 .                            # space

<< ptr1 +++++ +++++ +++++ .         # W
> ptr2 .                            # o
  ptr2 +++ .                        # r
  ptr2 ----- - .                    # l
  ptr2 ----- --- .                  # d
>> ptr4 .                           # !

> ptr5 .                            # LF
