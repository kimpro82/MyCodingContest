// 2941. LJESNJAK
// 2024.02.29

use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    let word = str.trim().as_bytes();
    
    let l2 = vec!["c=", "c-", "d-", "lj", "nj", "s=", "z="];
    let l3 = vec!["dz="];
    
    let len: usize = word.len();
    let mut count = len;
    for i in 0..(len-1)
    {
        if i < len-2
        {
            let s3 = &word[i..i+3].iter().map(|&c| c as char).collect::<String>();
            if l3[0] == s3 { count -= 2 - 1; }              // -1 : `z=` is also counted with `dz=`
            if test { println!("{} : {} {}", i, s3, count); }
        }
        let s2 = &word[i..i+2].iter().map(|&c| c as char).collect::<String>();
        for l in l2.iter() { if l == s2 { count -= 1; } }
        if test { println!("{} : {} {}", i, s2, count); }
    }

    println!("{}", count);
}
