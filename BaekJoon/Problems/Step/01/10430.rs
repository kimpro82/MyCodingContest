// 10430. 나머지
// 2023.12.21

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let numbers: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    let a = numbers[0];
    let b = numbers[1];
    let c = numbers[2];

    println!("{}", (a + b) % c);
    println!("{}", ((a % c) + (b % c)) % c);
    println!("{}", (a * b) % c);
    println!("{}", ((a % c) * (b % c)) % c);
}
