// 2675. Repeating Characters
// 2024.02.15


use std::io;

fn main()
{
    let mut p = String::new();
    io::stdin().read_line(&mut p).unwrap();
    let p:usize = p.trim().parse().unwrap();

    for _ in 0..p
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut inputs = input.trim().split_whitespace();

        let n:usize = inputs.next().unwrap().parse().unwrap();
        let str:String = inputs.next().unwrap().to_string();
        let len:usize = str.len();
        for i in 0..len
        {
            for _ in 0..n
            {
                print!("{}", str.chars().nth(i).unwrap());
            }
        }
        print!("\n");
    }
}
