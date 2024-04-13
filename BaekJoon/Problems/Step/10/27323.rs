// 27323. 長方形 (Rectangle, 직사강형)
// 2024.04.12


use std::io;

fn main()
{
    // Input a, b
    let mut a = String::new();
    let mut b = String::new();
    io::stdin().read_line(&mut a).unwrap();
    io::stdin().read_line(&mut b).unwrap();
    let a: i32 = a.trim().parse().unwrap();
    let b: i32 = b.trim().parse().unwrap();

    // Output
    println!("{}", a * b);
}
