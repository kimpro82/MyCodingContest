// 9506. Federation Favorites (약수들의 합)
// 2024.04.05


use std::io;

fn main()
{
    // let test: bool = true;
    let test: bool = false;

    loop
    {
        // Input n
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let n: i32 = input.trim().parse().unwrap();

        if n == -1 { break; }
        else
        {
            // Calc.
            let mut sum: i32 = 1;
            let mut str: String = format!("{} = 1", n);
            for i in 2..=n/2
            {
                if n % i == 0
                {
                    sum += i;
                    str += &format!(" + {}", i);
                }
                // Test
                if test { println!("{} : {} {}", i, sum, n); }

                if sum > n { break; }
            }

            // Output
            if sum == n { println!("{}", str); }
            else { println!("{} is NOT perfect.", n)}
        }
    }
}
