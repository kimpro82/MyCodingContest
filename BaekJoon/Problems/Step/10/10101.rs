// 10101. Triangle Times (삼각형 외우기)
// 2024.04.12


use std::io;

fn main()
{
    // Input a, b
    let mut a = String::new();
    let mut b = String::new();
    let mut c = String::new();
    io::stdin().read_line(&mut a).unwrap();
    io::stdin().read_line(&mut b).unwrap();
    io::stdin().read_line(&mut c).unwrap();
    let a: i32 = a.trim().parse().unwrap();
    let b: i32 = b.trim().parse().unwrap();
    let c: i32 = c.trim().parse().unwrap();

    // Judge
    let ans: String =
    {
        if a + b + c == 180
        {
            if a == 60 && b == 60              { "Equilateral".to_string() }    // no semicolon (why?)
            else if a == b || b == c || c == a { "Isosceles".to_string() }
            else                               { "Scalene".to_string() }
        }
        else                                   { "Error".to_string() }
    };

    // Output
    println!("{}", ans);
}
