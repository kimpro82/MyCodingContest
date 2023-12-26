// 10871. X보다 작은 수
// 2023.12.25

use std::io::{self, Read};
use std::fmt::Write;
use std::convert::TryInto;

fn main()
{
    let mut input = String::new();
    let mut output = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i32>);

    let n: usize = input.next().unwrap().try_into().unwrap();
    let x: i32 = input.next().unwrap();
    let mut v = Vec::<i32>::new();
    for _ in 0..n
    {
        let temp: i32 = input.next().unwrap();
        if temp < x { v.push(temp) };
    };

    for value in v { write!(output, "{} ", value).unwrap() };
    println!("{}", output);
}
