// 3009. CETVRTA (네 번째 점)
// 2024.04.12


use std::io;
use std::collections::HashMap;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input
    let mut x_map = HashMap::new();
    let mut y_map = HashMap::new();
    for _ in 0..3
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let x: i32 = iter.next().unwrap().parse().unwrap();
        let y: i32 = iter.next().unwrap().parse().unwrap();

        if test { println!("{} {}", x, y); }

        if x_map.get(&x) == None { x_map.insert(x, 1); }
        else { x_map.insert(x, 2); }                        // hope cnt + 1, not 2
        if y_map.get(&y) == None { y_map.insert(y, 1); }
        else { y_map.insert(y, 2); }
    }

    // Find the answer
    let mut x_ans: i32 = 0;
    let mut y_ans: i32 = 0;
    for (k, v) in x_map.iter() { if *v == 1 { x_ans = *k; } }
    for (k, v) in y_map.iter() { if *v == 1 { y_ans = *k; } }

    // Output
    println!("{} {}", x_ans, y_ans);
}
