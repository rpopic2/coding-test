use std::io::{stdin, Read};
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace().flat_map(str::parse::<i32>);
    let [h, m, c] = [0; 3].map(|_|iter.next().unwrap());
    let total = (h * 60 + m + c) % (24 * 60);
    println!("{} {}", total / 60, total % 60);
}
