// 1193. 분수찾기
// 2024.04.03


use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input n
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: u32 = n.trim().to_string().parse().unwrap();

    // Calc.
    let mut diag: u32 = 0;
    let mut benchmark: u32 = 0;
    while n > benchmark
    {
        diag += 1;
        benchmark += diag;

        if test { println!("{} : {} {}", diag, benchmark, n); }
    }
    let ans1: u32;
    let ans2: u32;
    if diag % 2 != 0
    {
        ans1 = benchmark - n + 1;
        ans2 = diag + 1 - ans1;
    }
    else
    {
        ans2 = benchmark - n + 1;
        ans1 = diag + 1 - ans2;
    }

    // Output
    println!("{}/{}", ans1, ans2);
}
