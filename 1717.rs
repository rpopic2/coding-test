use std::io::{stdin, Read};
use std::fmt::Write;

fn main() {
    let input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut toks = input.split_ascii_whitespace().flat_map(str::parse);
    let n = toks.next().unwrap();
    let m = toks.next().unwrap();

}
