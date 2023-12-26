// 3052. 나머지
// 2023.12.25

use std::io::{self, Read};

fn main()
{
    let mut input = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let input: Vec<usize> = input
        .split_whitespace()
        .map(|s| s.parse::<usize>().unwrap())
        .collect();

    let mut v = vec![0; 42];
    for el in input { v[el % 42] += 1 };

    let mut cnt = 0;
    for el in v { if el > 0 { cnt += 1 } };

    println!("{}", cnt);
}
