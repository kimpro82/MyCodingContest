// 2745. 진법 변환
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
    let n: Vec<char> = iter.next().unwrap().chars().collect();
    let b: u32 = iter.next().unwrap().parse().unwrap();

    // Convert n to decimal
    let mut ans = 0;
    let len = n.len();
    for i in 0..len
    {
        let c = if n[len-i-1] >= 'A' { n[len-i-1] as u32 - 'A' as u32 + 10 }
                else { n[len-i-1] as u32 - '0' as u32 };
        ans += c * (b as u32).pow(i as u32);
        if test { println!("{} : {} {} {}", i, n[len-i-1], c, ans); }
    }

    // Output
    println!("{}", ans);
}
