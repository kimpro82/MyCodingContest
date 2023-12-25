// 8393. Sum
// 2023.12.23

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();

    println!("{}", n * (n + 1) / 2);
}
