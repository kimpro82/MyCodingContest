// 10811. 바구니 뒤집기
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
        let i: usize = input.next().unwrap().try_into().unwrap();
        let j: usize = input.next().unwrap().try_into().unwrap();

        let v2_len: usize = (j-i+1).try_into().unwrap();
        let mut v2 = Vec::<i32>::with_capacity(v2_len);
        for k in i..(j+1) { v2.push(v[k-1]) };

        v2.reverse();

        for k in i..(j+1) { v[k-1] = v2[k-i] };

        // test
        // println!("i:{} j:{}", i, j);
        // for el in v2 { print!("{} ", el) }; println!();
        // for el in &v { print!("{} ", el) }; println!();
    };

    for el in v { print!("{} ", el) }; println!();
}
