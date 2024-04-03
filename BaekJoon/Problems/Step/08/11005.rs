// 11005. 진법 변환 2
// 2024.04.03


use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input n & b
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace(); 
    let mut n: u32 = iter.next().unwrap().parse().unwrap();
    let b: u32 = iter.next().unwrap().parse().unwrap();

    // Convert n to decimal
    let mut ans: String = String::new();
    while n > 0
    {
        let remainder: u32 = n % b;
        let c: char = if remainder >= 10 { char::from_u32(remainder - 10 + 'A' as u32).unwrap() }
                else { char::from_u32(remainder + '0' as u32).unwrap() };
        ans = c.to_string() + &ans;
        n /= b;
        if test { println!("{} : {} {} {}", n, remainder, c, ans); }
    }

    // Output
    println!("{}", ans);
}
