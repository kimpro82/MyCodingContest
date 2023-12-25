// 25314. 코딩은 체육과목 입니다
// 2023.12.23

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let mut n: i32 = input.trim().parse().unwrap();

    n /= 4;
    for _i in 0..n { print!("long ") };
    println!("int");
}
