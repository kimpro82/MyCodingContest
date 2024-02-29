// 10988. 팰린드롬인지 확인하기
// 2024.02.27

use std::io;

fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    let str = str.trim().to_string();
    let len: usize = str.len();
    let mut answer: i32 = 1;
    
    for i in 0..len/2
    {
        if str.chars().nth(i).unwrap() != str.chars().nth(len - i - 1).unwrap()
        {
            answer = 0;
            break;
        }
    }

    println!("{}", answer);
}
