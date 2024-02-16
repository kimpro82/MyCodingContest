// 9086. 문자열
// 2024.02.15


use std::io;

fn main()
{
    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();

    let t:usize = t.trim().parse().unwrap();
    for _ in 0..t
    {
        let mut str = String::new();
        io::stdin().read_line(&mut str).unwrap();
        let len = str.trim().len();

        println!("{}{}", str.chars().nth(0).unwrap(), str.chars().nth(len - 1).unwrap()); 
    }  
}
