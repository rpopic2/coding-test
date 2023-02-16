use std::io::stdin;

const PAY: i32 = 1_000;
const COINS: [i32; 6] = [500, 100, 50, 10, 5, 1];

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let input: i32 = input.trim().parse().unwrap();

    let mut change = PAY - input;
    let mut coins_count = 0;

    while change > 0 {
        for coin in COINS {
            let diff = change - coin;
            if diff < 0 {
                continue;
            }
            change = diff;
            coins_count += 1;
            break;
        }
    }

    println!("{}", coins_count);

}
