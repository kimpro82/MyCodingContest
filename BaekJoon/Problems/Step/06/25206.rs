// 25206. 너의 평점은
// 2024.02.29

use std::io;

fn main()
{
    let mut numerator: f32 = 0.0;
    let mut denominator: f32 = 0.0;
    let classes: i32 = 20;

    for _ in 0..classes
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut input = input.trim().split_whitespace();

        _ = input.next();
        let weight: f32 = input.next().unwrap().parse::<f32>().unwrap();
        let grade = input.next().unwrap().parse::<String>().unwrap();
        let grade_num: f32 = match grade.as_str() 
        {
            "A+" => 4.5,
            "A0" => 4.0,
            "B+" => 3.5,
            "B0" => 3.0,
            "C+" => 2.5,
            "C0" => 2.0,
            "D+" => 1.5,
            "D0" => 1.0,
            "F" => 0.0,
            _ => 0.0
        };
        if grade.as_str() != "P"
        {
            denominator += weight;
            numerator += grade_num * weight;
        }
    }

    let answer: f32 = numerator / denominator;
    println!("{}", answer);
}
