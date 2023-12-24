// 2438. 별 찍기 - 1
// 2023.12.23

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();

    for _i in 0..n
    {
        for _j in 0.._i+1 { print!("*") };
        println!();
    };
}
