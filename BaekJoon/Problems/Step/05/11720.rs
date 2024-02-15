// 11720. 숫자의 합
// 2024.02.15


use std::io;

fn main()
{
    let mut n = String::new();
    let mut num = String::new();
    io::stdin().read_line(&mut n).unwrap();
    io::stdin().read_line(&mut num).unwrap();

    let n:usize = n.trim().parse().unwrap();
    let mut sum:u32 = 0;
    for i in 0..n
    {
        let digit:u32 = num.chars().nth(i).unwrap().to_digit(10).unwrap();
        sum += digit;
    }

    println!("{}", sum);
}
