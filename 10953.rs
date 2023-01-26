use std::io::{stdin, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut toks = {
        stdin().read_to_string(&mut input).unwrap();
        input.split(&[',', ' ', '\n']).flat_map(str::parse)
    };
    let n = toks.next().unwrap();
    let mut buf = String::new();
    for _ in 0..n {
        let a = toks.next().unwrap();
        let b = toks.next().unwrap();
        writeln!(buf, "{}", a + b).unwrap();
    }
    print!("{}", buf);
}
