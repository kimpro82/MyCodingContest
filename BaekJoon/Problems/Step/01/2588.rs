// 2588. 곱셈
// 2023.12.21

use std::io;

fn main()
{
    let mut input1 = String::new();
    let mut input2 = String::new();

    io::stdin().read_line(&mut input1).unwrap();
    io::stdin().read_line(&mut input2).unwrap();

    let a: i32 = input1.trim().parse().unwrap();
    let b = input2.to_string().chars().collect::<Vec<char>>();

    let prod1 = a * (b[2] as i32 - '0' as i32);
    let prod2 = a * (b[1] as i32 - '0' as i32);
    let prod3 = a * (b[0] as i32 - '0' as i32);

    println!("{}", prod1);
    println!("{}", prod2);
    println!("{}", prod3);
    println!("{}", prod1 + prod2 * 10 + prod3 * 100);
}
