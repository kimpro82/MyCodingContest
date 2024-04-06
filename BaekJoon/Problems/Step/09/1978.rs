// 1978. 소수 찾기
// 2024.04.05


use std::io;

fn is_prime(num: i32, test: bool) -> bool
{
    if num == 1 { return false; }
    else if num == 2 { return true; }                       // crazy
    else
    {
        for i in 2..=(num as f32).sqrt().ceil() as i32
        {
            if test { println!("{} % {} = {}", num, i, num % i); }
            if num % i == 0 { return false; }
        }
        return true;
    }
}

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input n and n numbers
    let mut n = String::new();                              // not use
    let mut nums = String::new();
    io::stdin().read_line(&mut n).unwrap();
    io::stdin().read_line(&mut nums).unwrap();
    let nums: Vec<i32> = nums.split_whitespace()
        .map(|s| s.parse().unwrap()).collect();

    // Count the number of prime numbers
    let mut cnt: i32 = 0;
    for i in 0..nums.len()
    {
        if is_prime(nums[i], test) { cnt += 1; }
    }

    // Output
    println!("{}", cnt);
}
