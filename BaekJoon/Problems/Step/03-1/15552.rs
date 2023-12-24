// 15552. 빠른 A+B
// 2023.12.24

use std::io::{self, Read};
use std::fmt::Write;

fn main()
{
    let mut input = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i32>);

    let t = input.next().unwrap();
    let mut output = String::new();
    for _ in 0..t
    {
        let a: i32 = input.next().unwrap();
        let b: i32 = input.next().unwrap();
    
        writeln!(output, "{}", a + b).unwrap();
    }
    print!("{}", output);
}
