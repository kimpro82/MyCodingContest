// 1085. 직사각형에서 탈출
// 2024.04.12


use std::io;
use std::cmp::min;

fn main()
{
    // Input x, y, w, h
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let x: i32 = iter.next().unwrap().parse().unwrap();
    let y: i32 = iter.next().unwrap().parse().unwrap();
    let w: i32 = iter.next().unwrap().parse().unwrap();
    let h: i32 = iter.next().unwrap().parse().unwrap();

    // Calc.
    let mut ans: i32 = 1_000;
    ans = min(x, ans);
    ans = min(y, ans);
    ans = min(w - x, ans);
    ans = min(h - y, ans);

    // Output
    println!("{}", ans);
}
