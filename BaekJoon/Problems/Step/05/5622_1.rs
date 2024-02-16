// 5622. BAKA - Trial 1
// 2024.02.15


use std::io;

fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let len:usize = str.trim().len();
    let mut sum:i32 = len as i32;
    for i in 0..len
    {
        let c:char = str.chars().nth(i).unwrap();
        match c                                             // All possible cases should be handled in `match` statement!
        {
            'A' | 'B' | 'C' => sum += 2,
            'D' | 'E' | 'F' => sum += 3,
            'G' | 'H' | 'I' => sum += 4,
            'J' | 'K' | 'L' => sum += 5,
            'M' | 'N' | 'O' => sum += 6,
            'P' | 'Q' | 'R' | 'S' => sum += 7,
            'T' | 'U' | 'V' => sum += 8,
            _ => sum += 9
        }
    }

    println!("{}", sum);
}
