// 10813. 공 바꾸기
// 2023.12.25

use std::io::{self, Read};
use std::convert::TryInto;

fn main()
{
    let mut input = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i32>);

    let n: usize = input.next().unwrap().try_into().unwrap();
    let m: usize = input.next().unwrap().try_into().unwrap();
    let mut v = Vec::<i32>::with_capacity(n);
    for i in 0..n { v.push((i + 1).try_into().unwrap()) };
    for _ in 0..m
    {
        let i: i32 = input.next().unwrap() - 1;
        let j: i32 = input.next().unwrap() - 1;

        v.swap(i as usize, j as usize);                     // wow!
    };

    for el in v { print!("{} ", el) };
    println!();
}
