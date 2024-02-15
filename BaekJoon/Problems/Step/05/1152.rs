// 1152. 단어의 개수
// 2024.02.15


use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let words: Vec<&str> = input.trim().split_whitespace().collect();

    let cnt = words.len();
    println!("{}", cnt);
}
