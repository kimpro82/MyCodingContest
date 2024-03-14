// 2563. 색종이
// 2024.03.13


use std::io;

fn main()
{
    // Declare r, c
    let r: usize = 100;
    let c: usize = 100;

    // Input the number of rows
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();

    let mut matrix: Vec<Vec<i32>> = vec![vec![0; c]; r];
    for i in 0..n
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();                                 // should be declared as mutable
        let n: usize = iter.next().unwrap().parse().unwrap();
        let m: usize = iter.next().unwrap().parse().unwrap();

        for j in n..n+10
        {
            for k in m..m+10
            {
                matrix[j][k] = 1;
            }
        }
    }

    // Count the number of 1s
    let mut count: i32 = 0;
    for i in 0..r
    {
        for j in 0..c
        {
            count += matrix[i][j];
        }
    }

    // Output
    println!("{}", count);
}
