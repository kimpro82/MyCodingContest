// 2444. 별 찍기 - 7
// 2024.02.27

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();
    let rows: i32 = 2 * n - 1;

    for i in 0..rows
    {
        for j in 0..rows
        {
            if i < n
            {
                if j >= rows - (n - i - 1) { continue }
                else if j >= n - i - 1     { print!("*") }
                else                       { print!(" ") }
                
            }
            else
            {
                if j >= rows + (n - i - 1) { continue }
                else if j > i - n          { print!("*") }
                else                       { print!(" ") }
            }
        }
        println!();
    }
}
