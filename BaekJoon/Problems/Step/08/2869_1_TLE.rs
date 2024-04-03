// 2869. PUŽ (달팽이는 올라가고 싶다)
// 2024.04.03


use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input a, b & v
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace(); 
    let a: u32 = iter.next().unwrap().parse().unwrap();
    let b: u32 = iter.next().unwrap().parse().unwrap();
    let v: u32 = iter.next().unwrap().parse().unwrap();

    // Calc.
    let mut day: u32 = 0;
    let mut climb: u32 = 0;
    while climb < v
    {
        day += 1;
        climb += a;
        if climb >= v { break; }
        climb -= b;

        if test { println!("Day {} : {} meter(s)", day, climb); }
    }

    // Output
    println!("{}", day);
}

// 시간 초과
