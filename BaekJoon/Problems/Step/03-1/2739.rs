// 2739. 구구단
// 2023.12.23

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();

    for i in 1..10 { println!("{} * {} = {}", n, i, n * i); };
    // ; can be skipped
}
