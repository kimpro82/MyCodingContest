// 9063. 대지
// 2024.04.12


use std::io;
use std::cmp;

fn main()
{

    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: i32 = n.trim().parse().unwrap();

    // Input x, y n times
    let mut x_min = 10_000;
    let mut x_max = -10_000;
    let mut y_min = 10_000;
    let mut y_max = -10_000;
    for _ in 0..n
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let x: i64 = iter.next().unwrap().parse().unwrap();
        let y: i64 = iter.next().unwrap().parse().unwrap();

        x_min = cmp::min(x_min, x);
        x_max = cmp::max(x_max, x);
        y_min = cmp::min(y_min, y);
        y_max = cmp::max(y_max, y);
    }

    // Output
    let ans: i64 = (x_max - x_min) * (y_max - y_min);
    println!("{}", ans);
}
