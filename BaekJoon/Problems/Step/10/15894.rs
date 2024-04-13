// 15894. 수학은 체육과목 입니다
// 2024.04.12


use std::io;

fn main()
{
    // Input n
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: i64 = n.trim().parse().unwrap();

    // Output
    println!("{}", n * 4);
}
