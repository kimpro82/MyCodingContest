// 1157. 단어 공부
// 2024.02.27

use std::io;

fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    str = str.trim().to_string().to_uppercase();
    let word: Vec<char> = str.chars().collect();

    let mut v: Vec<i32> = vec![0; 26];
    let mut mode: (char, i32) = (' ', 0);

    let len: usize = word.len();
    for i in 0..len
    {
        let c: char = word[i];
        let idx: usize = c as usize - 'A' as usize;
        v[idx] += 1;

        if v[idx] > mode.1 { mode = (c, v[idx]) }
        else if v[idx] == mode.1 { mode = ('?', v[idx]) }
    }

    println!("{}", mode.0);
}
