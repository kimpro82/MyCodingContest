// 10810. 공 넣기
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
    let mut v = vec![0; n];
    for _ in 0..m
    {
        let i: usize = input.next().unwrap().try_into().unwrap();
        let j: usize = input.next().unwrap().try_into().unwrap();
        let k: i32 = input.next().unwrap();

        for l in i..(j+1) { v[l-1] = k };
    };

    for el in v { print!("{} ", el) };
    println!();
}
