fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let len:usize = str.trim().len();
    let mut sum:i32 = 0 as i32;
    for i in 0..len
    {
        let dial:char = str.chars().nth(i).unwrap();
        let time:i32 = match dial
        {
            // All possible cases should be handled in `match` statement!
            'A' | 'B' | 'C' => 2,
            'D' | 'E' | 'F' => 3,
            'G' | 'H' | 'I' => 4,
            'J' | 'K' | 'L' => 5,
            'M' | 'N' | 'O' => 6,
            'P' | 'Q' | 'R' | 'S' => 7,
            'T' | 'U' | 'V' => 8,
            _ => 9
        };

        sum += time + 1;
    }

    println!("{}", sum);
}
