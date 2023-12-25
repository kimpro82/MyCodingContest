// 10952. A+B - 5
// 2023.12.23

use std::io;

fn main()
{
    loop
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let numbers: Vec<i32> = input
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();

        let a = numbers[0];
        let b = numbers[1];

        if a == 0 && b == 0 { break; }
        else { println!("{}", a + b) };
    }
}
