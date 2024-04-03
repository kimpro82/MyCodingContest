// 2720. 세탁소 사장 동혁
// 2024.04.03


use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();
    let t: u32 = t.trim().to_string().parse().unwrap();

    for _ in 0..t
    {
        // Input c
        let mut c = String::new();
        io::stdin().read_line(&mut c).unwrap();
        let mut c: u32 = c.trim().to_string().parse().unwrap();

        // Count coins
        let mut count = vec![0; 4];
        let coin = vec![25, 10, 5, 1];
        for i in 0..4
        {
            count[i] = c / coin[i];
            c %= coin[i];
            if test { println!("{} : {} {} {}", i, c, coin[i], count[i]); }
        }

        // Output
        println!("{} {} {} {}", count[0], count[1], count[2], count[3]);
    }
}
