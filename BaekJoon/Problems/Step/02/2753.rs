// 2753. 윤년
// 2023.12.22

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();
    let ans: i32 =
        if n % 4 == 0 && (n % 100 != 0 || n % 400 == 0) { 1 }
        else { 0 };

    println!("{}", ans);
}
