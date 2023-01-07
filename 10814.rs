use std::fmt::Write;
use std::io::{stdin, Read};
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut tok = input.split_ascii_whitespace();
    let n = tok.next().unwrap().parse().unwrap();
    let mut members: Vec<(i32, &str)> = vec![];
    for _ in 0..n {
        let age: i32 = tok.next().unwrap().parse().unwrap();
        let name = tok.next().unwrap();
        members.push((age, name));
    }
    members.sort_by(|lhs, rhs| lhs.0.cmp(&rhs.0));
    let mut buf = String::new();
    for m in members {
        writeln!(&mut buf, "{} {}", m.0, m.1).unwrap();
    }
    print!("{buf}");
}
