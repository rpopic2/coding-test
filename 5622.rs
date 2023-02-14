use std::io::stdin;
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let input = input.trim();

    let mut acc = 0;
    for c in input.chars() {
        let number = match c {
            'A'..='C' => 3,
            'D'..='F' => 4,
            'G'..='I' => 5,
            'J'..='L' => 6,
            'M'..='O' => 7,
            'P'..='S' => 8,
            'T'..='V' => 9,
            'W'..='Z' => 10,
            _ => panic!()
        };
        acc += number;
    }
    println!("{}", acc);
}
