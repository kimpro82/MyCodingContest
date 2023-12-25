// 10818. 최소, 최대
// 2023.12.25

use std::convert::TryInto;
use std::io::{self, Read};

fn main()
{
    let mut input = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let n: usize = input.next().unwrap().try_into().unwrap();
    // let mut max: i32 = -10^6;                            // ^ : Bitwise operation
    // let mut min: i32 = 10^6;
    let mut max: i32 = -1_000_000;
    let mut min: i32 = 1_000_000;
    for _ in 0..n {
        let temp: i32 = input.next().unwrap();
        if temp > max { max = temp };
        if temp < min { min = temp };

        // test
        // println!("num: {}, max: {}, min: {}", temp, max, min);
    }

    println!("{} {}", min, max);
}

// trial 1 - 틀렸습니다
// num: 20, max: 20, min: 12 ???
// num: 10, max: 20, min: 10
// num: 35, max: 35, min: 10
// num: 30, max: 35, min: 10
// num: 7, max: 35, min: 7
// 7 35

// trial 2 - 맞았습니다!!
