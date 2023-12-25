// 2562. 최댓값
// 2023.12.25

use std::io::{self, Read};

fn main()
{
    let mut input = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i32>);

    let mut max: i32 = 0;
    let mut idx: i32 = 0;
    for i in 0..9
    {
        let temp: i32 = input.next().unwrap();
        if temp > max
        {
            max = temp;
            idx = i + 1;
        };
    };

    println!("{}\n{}", max, idx);
}
