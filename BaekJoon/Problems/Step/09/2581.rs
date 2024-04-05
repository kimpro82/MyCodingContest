// 2581. 소수
// 2024.04.05


use std::io;

fn is_prime(num: i32, test: bool) -> bool
{
    if num == 1 { return false; }
    else if num == 2 { return true; }
    else
    {
        for i in 2..=(num as f32).sqrt().ceil() as i32
        {
            if test { println!("{} % {} = {}", num, i, num % i); }
            if num % i == 0 { return false; }
        }
        return true;
    }
}

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input m, n
    let mut m = String::new();
    let mut n = String::new();
    io::stdin().read_line(&mut m).unwrap();
    io::stdin().read_line(&mut n).unwrap();
    let m: i32 = m.trim().parse().unwrap();
    let n: i32 = n.trim().parse().unwrap();

    // Calc.
    let mut sum: i32 = 0;
    let mut min: i32 = 0;
    for i in m..=n
    {
        if is_prime(i, test)
        {
            sum += i;
            if min == 0 { min = i; }
        }
    }

    // Output
    if sum > 0 { println!("{}\n{}", sum, min); }
    else       { println!("-1"); }
}
