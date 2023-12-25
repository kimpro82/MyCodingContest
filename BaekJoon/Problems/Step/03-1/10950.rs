// 10950. A+B - 3
// 2023.12.23

use std::io;

fn main()
{
    let mut input1 = String::new();
    io::stdin().read_line(&mut input1).unwrap();
    let t: i32 = input1.trim().parse().unwrap();

    for _i in 0..t
    // `_i`, not `i` when intentional
    {
        let mut input2 = String::new();
        io::stdin().read_line(&mut input2).unwrap();
        let numbers: Vec<i32> = input2
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap())
            .collect();

        let a = numbers[0];
        let b = numbers[1];

        println!("{}", a + b);
    }
}
