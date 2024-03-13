// 2566. 최댓값
// 2024.03.12


use std::io;

fn main()
{
    // Declare n, m
    let n: usize = 9;
    let m: usize = 9;

    // Find the max value and its location (max_i, max_j)
    let mut max: i32 = -1;
    let mut max_i: usize = 0;
    let mut max_j: usize = 0;
    for i in 0..n
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let row: Vec<i32> = line.split_whitespace()
            .map(|s| s.parse().unwrap()).collect();

        for j in 0..m
        {
            if row[j] > max
            {
                max = row[j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // Output
    println!("{}", max);
    println!("{} {}", max_i + 1, max_j + 1);
}
