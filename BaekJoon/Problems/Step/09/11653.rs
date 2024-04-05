// 11653. 소인수분해
// 2024.04.05


use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input n
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let mut n: i32 = n.trim().parse().unwrap();

    // Calc. and Output
    let m: i32 = (n as f32).sqrt().ceil() as i32;
    for mut i in 2..=n
    {
        if i > m { i = n; }                                 // for performance
        loop
        {
            if n % i == 0
            {
                n /= i;
                
                if test { println!("{} : {}", i, n); }
                else    { println!("{}", i); }
            }
            else { break; }
        }
        if n == 1 { return; }
    }
}
