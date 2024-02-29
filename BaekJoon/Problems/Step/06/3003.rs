// 3003. BIJELE (킹, 퀸, 룩, 비숍, 나이트, 폰)
// 2024.02.26

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let pieces: Vec<i32> = input
        .trim().split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();
    let standard: Vec<i32> = vec![1, 1, 2, 2, 2, 8];

    for i in 0..6 { print!("{} ", standard[i] - pieces[i]); }
    println!();
}
