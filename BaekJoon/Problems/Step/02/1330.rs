// 1330. 두 수 비교하기
// 2023.12.22

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
    let ans: String =                                       // works?
        if a > b { ">".to_string() }
        else if a < b { "<".to_string() }
        else { "==".to_string() };

    println!("{}", ans);
}
