// 2743. 단어 길이 재기
// 2024.01.17


use std::io;

fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let len = str.trim().len();
    println!("{}", len);
}
