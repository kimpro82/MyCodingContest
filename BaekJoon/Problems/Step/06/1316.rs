// 1316. 그룹 단어 체커
// 2024.02.29

use std::io;

fn main()
{
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n:usize = n.trim().parse().unwrap();

    let mut count: i32 = 0;
    for _ in 0..n
    {
        let mut str = String::new();
        io::stdin().read_line(&mut str).unwrap();
        let word = str.trim().as_bytes();

        let mut v: Vec<i32> = vec![0; 26];
        let mut grouped: bool = true;
        
        let len: usize = word.len();
        for i in 0..len
        {
            let idx: usize = word[i] as usize - 'a' as usize;

            if v[idx] == 0 || word[i] == word[i-1] { v[idx] = 1 }
            else
            {
                grouped = false;
                break;
            }
        }
        if grouped { count += 1 }
    }

    println!("{}", count);
}
