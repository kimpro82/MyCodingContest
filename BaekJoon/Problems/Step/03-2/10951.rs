// 10951. A+B - 4
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

        if numbers.len() == 0 { break; }                    // EOF
        else
        {
            let sum: i32 = numbers[0] + numbers[1];
            println!("{}", sum);
        };
    }
}
