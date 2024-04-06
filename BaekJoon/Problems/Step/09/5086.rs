// 5086. Factors And Multiples (배수와 약수)
// 2024.04.05


use std::io;

fn main()
{
    loop
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();

        if a == 0 && b == 0 { break; }
        else
        {
            if a > b && a % b == 0 { println!("multiple") }
            else if a < b && b % a == 0 { println!("factor") }
            else { println!("neither") }
        };
    }
}
