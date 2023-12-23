// 14681. Quadrant Selection
// 2023.12.22

use std::io;

fn main()
{
    let mut input1 = String::new();
    let mut input2 = String::new();

    io::stdin().read_line(&mut input1).unwrap();
    io::stdin().read_line(&mut input2).unwrap();

    let a: i32 = input1.trim().parse().unwrap();
    let b: i32 = input2.trim().parse().unwrap();

    let ans =
        if a > 0
        {
            if b > 0 { 1 }
            else { 4 }
        }
        else
        {
            if b > 0 { 2 }
            else { 3 }
        };

    println!("{}", ans);
}
