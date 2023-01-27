use std::io::stdin;

fn next_cycle(n: i32) -> i32 {
    let sum = n / 10 + n % 10;
    n % 10 * 10 + sum % 10
}

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    let mut counter = 0;
    let mut last_cycle = n;

    loop {
        last_cycle = next_cycle(last_cycle);
        counter += 1;
        if last_cycle == n { break; }
    }
    println!("{}", counter);
}
