// 18108. 1998년생인 내가 태국에서는 2541년생?!
// 2023.12.21

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    println!("{}??!", input.replace("\n", ""));
}
