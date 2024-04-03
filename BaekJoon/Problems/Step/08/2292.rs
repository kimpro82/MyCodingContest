// 2292. 벌집
// 2024.04.03

// 1 > 1
// 2 > 1 + 6 = 7
// 3 > 1 + 6 + 12 = 19
// 4 > 1 + 6 + 12 + 18 = 37


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
    let mut ans: u32 = 1;
    let mut benchmark: u32 = 1;
    while n > benchmark
    {
        ans += 1;
        benchmark += 6 * (ans - 1);

        if test { println!("{} : {} {}", ans, benchmark, n); }
    }

    // Output
    println!("{}", ans);
}
