// 2903. PLANINA (중앙 이동 알고리즘)
// 2024.04.03

// 0 >    4 =  2^2 = (2^0 + 1)^2
// 1 >    9 =  3^2 = (2^1 + 1)^2
// 2 >   25 =  5^2 = (2^2 + 1)^2
// 5 > 1089 = 33^2 = (2^5 + 1)^2


use std::io;

fn main()
{
    // Input n
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: u32 = n.trim().to_string().parse().unwrap();

    // Output
    let ans: u32 = ((2 as u32).pow(n) + 1).pow(2);
    println!("{}", ans);
}
