// 14215. 세 막대
// 2024.04.12


use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input a, b, c
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).unwrap();
    let mut nums: Vec<i32> = nums.split_whitespace()
                             .map(|s| s.parse().unwrap()).collect();

    // Sort in ascending order
    nums.sort();
    if test { println!("Before : {:?}", nums); }

    // Output
    if nums[0] + nums[1] <= nums[2] { nums[2] = nums[0] + nums[1] - 1; }
    if test { println!("After  : {:?}", nums); }
    println!("{}", nums[0] + nums[1] + nums[2]);
}
