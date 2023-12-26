// 10807. 개수 세기
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
    let mut vector = Vec::<i32>::new();
    for _ in 0..n { vector.push(input.next().unwrap()) };
    let v = input.next().unwrap();

    let mut cnt: i32 = 0;
    for i in 0..n { if vector[i] == v { cnt += 1 } };       // `cnt++` doesn't work
    println!("{}", cnt);
}
