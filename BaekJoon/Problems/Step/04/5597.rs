// 5597. 未提出者は誰だ (과제 안 내신 분..?)
// 2023.12.25

use std::io::{self, Read};

fn main()
{
    let mut input = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<usize>);

    let mut v = vec![1; 31];
    for _ in 0..28
    {
        let temp: usize = input.next().unwrap();
        v[temp] = 0;
    };

    for i in 1..31 { if v[i] == 0 { println!("{}", i) } };
}
