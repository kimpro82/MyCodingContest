// 2480. 주사위 세개
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
    let c = numbers[2];

    let ans =
        if a == b && b == c { 10000 + a * 1000 }
        else if a == b { 1000 + a * 100 }
        else if b == c { 1000 + b * 100 }
        else if c == a { 1000 + c * 100 }
        else
        {
            if a > b && a > c { a * 100 }
            else if b > a && b > c { b * 100 }
            else { c * 100 }
        };

        println!("{}", ans);
}
