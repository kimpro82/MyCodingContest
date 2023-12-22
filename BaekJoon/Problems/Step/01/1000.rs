// 1000. A+B
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

    let sum: i32 = numbers.iter().sum();

    println!("{}", sum);
}
