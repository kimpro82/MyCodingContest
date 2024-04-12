// 5073. Triangles (삼각형과 세 변)
// 2024.04.12


use std::io;

fn main()
{
    loop
    {
        // Input a, b, c
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        let c: i32 = iter.next().unwrap().parse().unwrap();

        // Judge and Output
        if a > 0
        {
            if a + b > c && b + c > a && c + a > b
            {
                if a == b && b == c && c == a      { println!("Equilateral"); }
                else if a == b || b == c || c == a { println!("Isosceles"); }
                else                               { println!("Scalene"); }
            }
            else                                   { println!("Invalid"); }
        }
        else                                       { break; }
    }
}
