// 10798. 세로읽기
// 2024.03.13


use std::io;

fn main()
{
    // Declare n, m
    let n: usize = 5;
    let m: usize = 15;

    // Input an array
    let mut arr: Vec<Vec<char>> = Vec::new();
    let mut lens: Vec<usize> = Vec::new();
    for i in 0..n
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let row: Vec<char> = line.trim().chars().collect();

        lens.push(row.len());
        arr.push(row);
    }

    // Output
    for i in 0..m
    {
        for j in 0..n
        {
            if i < lens[j] { print!("{}", arr[j][i]); }
        }
    }
    println!();
}
