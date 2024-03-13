// 2738. 행렬 덧셈
// 2024.03.12


use std::io;

fn main()
{
    // Input n, m
    let mut nm = String::new();
    io::stdin().read_line(&mut nm).unwrap();
    let mut iter = nm.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    // Input arr1, arr2
    let mut arr1: Vec<Vec<i32>> = Vec::new();
    let mut arr2: Vec<Vec<i32>> = Vec::new();
    for i in 0..(n * 2)
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let row: Vec<i32> = line.split_whitespace()
            .map(|s| s.parse().unwrap()).collect();

        if i < n { arr1.push(row) }
        else { arr2.push(row) };
    }

    // arr1 + arr2
    let mut sum: Vec<Vec<i32>> = Vec::new();
    for i in 0..n
    {
        let mut row: Vec<i32> = Vec::new();
        for j in 0..m { row.push(arr1[i][j] + arr2[i][j]) };
        sum.push(row);
    }

    // Output
    for i in 0..n
    {
        for j in 0..m { print!("{} ", sum[i][j]) };
        println!();
    }
}
