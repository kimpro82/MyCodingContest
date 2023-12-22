// 9498. 시험 성적
// 2023.12.22

use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let n: i32 = input.trim().parse().unwrap();
    let v = vec!['F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'];
    // [], not {}

    println!("{}", &v[(n/10) as usize]);
    // neither [n/10] nor [n/10 as usize]
}
