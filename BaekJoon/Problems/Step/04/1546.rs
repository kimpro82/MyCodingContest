// 1546. 평균
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

    let mut v: Vec<i32> = Vec::<i32>::with_capacity(n);
    for _ in 0..n { v.push(input.next().unwrap())};

    let mut max: i32 = 0;
    for el in &v { if *el > max { max = *el } };

    let mut v2: Vec<f32> = Vec::<f32>::with_capacity(n);
    for el in &v { v2.push(*el as f32 / max as f32 * 100.0) };

    let mut sum: f32 = 0.0;
    for el in &v2 { sum += *el };
    let mean: f32 = sum / (n as f32);

    println!("{}", mean);
}
