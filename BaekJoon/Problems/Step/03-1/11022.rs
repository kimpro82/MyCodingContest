// 11022. A+B - 8
// 2023.12.23

use std::io;

fn main()
{
    let mut input1 = String::new();
    io::stdin().read_line(&mut input1).unwrap();
    let t: i32 = input1.trim().parse().unwrap();

    for i in 1..t+1
    {
        let mut input2 = String::new();
        io::stdin().read_line(&mut input2).unwrap();
        let numbers: Vec<i32> = input2
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();

        let a = numbers[0];
        let b = numbers[1];

        println!("Case #{}: {} + {} = {}", i, a, b, a + b);
    }
}
