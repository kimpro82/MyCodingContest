// 2869. PUŽ (달팽이는 올라가고 싶다)
// 2024.04.03


use std::io;

fn main()
{
    // Input a, b & v
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace(); 
    let a: u32 = iter.next().unwrap().parse().unwrap();
    let b: u32 = iter.next().unwrap().parse().unwrap();
    let v: u32 = iter.next().unwrap().parse().unwrap();

    // Calc. without while loop
    let mut day: u32 = (v - a) / (a - b) + 1;
    if (v - a) % (a - b) != 0 { day += 1; }

    // Output
    println!("{}", day);
}
