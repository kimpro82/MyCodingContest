// 2908. FILIP
// 2024.02.15


use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut nums = input.trim().split_whitespace();

    let num1: i32 = nums.next().unwrap().chars().rev().collect::<String>().parse().unwrap();
    let num2: i32 = nums.next().unwrap().chars().rev().collect::<String>().parse().unwrap();

    let max: i32 = if num1 > num2 { num1 } else { num2 };
    println!("{}", max);
}
