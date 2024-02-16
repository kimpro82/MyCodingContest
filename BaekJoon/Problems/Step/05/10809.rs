// 10809. 알파벳 찾기
// 2024.02.15


use std::io;

fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let mut v: Vec<i32> = vec![-1; 26];

    let len:usize = str.trim().len();
    for i in 0..len
    {
        let c:char = str.chars().nth(i).unwrap();
        if v[c as usize - 'a' as usize] < 0 { v[c as usize - 'a' as usize] = i as i32 }
    }

    for i in 0..26 { print!("{} ", v[i]); }
    println!();
}
