// 11654. 아스키 코드
// 2024.02.15


use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    if let Some(char) = input.trim().chars().next()
    {
        let ascii_code = char as u8;
        println!("{}", ascii_code);
    }
}
