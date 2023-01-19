use std::io::{stdin, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut tok = input.split_ascii_whitespace().map(str::parse).flatten();
    let mut buf = String::new();
    loop {
        let a: u128 = tok.next().unwrap();
        let b = tok.next().unwrap();
        let c = tok.next().unwrap();
        if a == 0 && b == 0 && c == 0 {break};

        let mut threes = vec![a, b, c];
        threes.sort();

        let is_tri = threes[0].pow(2) + threes[1].pow(2) == threes[2].pow(2);
        let msg = if is_tri {"right"} else {"wrong"};
        writeln!(&mut buf, "{}", msg).unwrap();
    }
    print!("{}", buf);
}
