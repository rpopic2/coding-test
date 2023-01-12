use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse().unwrap();
    let mut acc = 0;
    for i in 1..=n {
        acc += i;
    }
    println!("{}", acc);
}
