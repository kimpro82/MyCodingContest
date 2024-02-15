// 27866. 문자와 문자열
// 2024.01.17

use std::io;

fn main()
{
    let mut input1 = String::new();
    let mut input2 = String::new();
    io::stdin().read_line(&mut input1).unwrap();
    io::stdin().read_line(&mut input2).unwrap();

    let i:usize = input2.trim().parse().unwrap();
    // trim `\n` caused by read_line()

    if let Some(chr) = input1.chars().nth(i - 1) { println!("{}", chr) };
}
