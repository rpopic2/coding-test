use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse);

    let n: i32 = input.next().unwrap();
    let acc: i32 = input.sum();
    println!("{}", acc - n + 1);
}
