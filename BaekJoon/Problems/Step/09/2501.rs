// 2501. 약수 구하기
// 2024.04.05


use std::io;

fn main()
{
    // Input n, k
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: i32 = iter.next().unwrap().parse().unwrap();
    let k: i32 = iter.next().unwrap().parse().unwrap();

    // Calc. and Output
    let mut cnt: i32 = 0;
    for i in 1..=n
    {
        if n % i == 0
        {
            cnt += 1;
            if cnt == k
            {
                println!("{}", i);                          // i, not cnt
                return;
            }
        }
    }

    // Output when k is not in [1, n]
    println!("0");
}
