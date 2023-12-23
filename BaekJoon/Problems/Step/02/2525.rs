// 2525. 오븐 시계
// 2023.12.22

use std::io;

fn main()
{
    let mut input1 = String::new();
    let mut input2 = String::new();

    io::stdin().read_line(&mut input1).unwrap();
    io::stdin().read_line(&mut input2).unwrap();

    let numbers: Vec<i32> = input1
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();
    let numbers2: i32 = input2.trim().parse().unwrap();

    let mut a = numbers[0];
    let mut b = numbers[1];
    let c = numbers2;

    b += c;
    a += b / 60;
    b %= 60;
    a %= 24;

    println!("{} {}", a, b);
}
