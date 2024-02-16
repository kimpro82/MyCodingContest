// 11718. 그대로 출력하기
// 2024.02.15

use std::io;

fn main()
{
    loop
    {
        let mut str = String::new();
        io::stdin().read_line(&mut str).unwrap();

        if str.len() == 0 { break; }                        // EOF
        else { print!("{}", str); };
    }
}
