use std::io::{stdin, Read};
use std::fmt::Write;

fn get_input() -> Vec<i32> {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut tok = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    tok.next().unwrap();
    tok.collect()
}
fn main() {
    let mut nums = get_input();
    let mut buf = String::new();
    nums.sort();
    for i in nums {
        writeln!(buf, "{}", i).unwrap();
    }
    print!("{}", buf);
}
