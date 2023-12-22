// 9498. 시험 성적
// 2023.12.22

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();
    let ans: char =
        if n >= 90 { 'A' }
        else if n >= 80 { 'B' }
        else if n >= 70 { 'C' }
        else if n >= 60 { 'D' }
        else { 'F' };

    println!("{}", ans);                                    // "{}", not '{}'
}
