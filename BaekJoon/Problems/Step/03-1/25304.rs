// 25304. 영수증
// 2023.12.23

use std::io;

fn main()
{
    let mut input1 = String::new();
    let mut input2 = String::new();

    io::stdin().read_line(&mut input1).unwrap();
    io::stdin().read_line(&mut input2).unwrap();

    let x: i32 = input1.trim().parse().unwrap();
    let n: i32 = input2.trim().parse().unwrap();

    let mut sum: i32 = 0;
    for _i in 0..n
    // `_i`, not `i` when intentional
    {
        let mut input3 = String::new();
        io::stdin().read_line(&mut input3).unwrap();
        let numbers: Vec<i32> = input3
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();

        let a = numbers[0];
        let b = numbers[1];

        sum += a * b;
    }

    let ans: String =
        if sum == x { "Yes".to_string() }
        else { "No".to_string() };

    println!("{}", ans);
}
