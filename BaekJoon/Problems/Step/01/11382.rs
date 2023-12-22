// 11382. 꼬마 정민
// 2023.12.21

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let numbers: Vec<i64> = input
        .split_whitespace()
        .map(|s| s.parse::<i64>().unwrap())
        .collect();

    let sum: i64 = numbers.iter().sum();

    println!("{}", sum);
}
