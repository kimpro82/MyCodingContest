// 2439. 별 찍기 - 2
// 2023.12.23

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();

    for i in 0..n
    {
        for j in 0..n
        {
            if j < n - i - 1 { print!(" ") }
            else { print!("*") }
        }
        println!();
    }
}
