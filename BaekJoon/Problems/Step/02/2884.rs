// 2884. SPAVANAC
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

    let mut a = numbers[0] + 24;
    let mut b = numbers[1];

    if b >= 45
    {
        b -= 45;
    }
    else
    {
        a -= 1;
        b += 60 - 45;
    }
    a %= 24;

    println!("{} {}", a, b);
}
