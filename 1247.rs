use std::io::{stdin, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut toks = {
        stdin().read_to_string(&mut input).unwrap();
        input.split_ascii_whitespace().flat_map(str::parse)
    };
    let mut buf = String::new();
    for _ in 0..3 {
        let n = toks.next().unwrap();
        let mut acc: i128 = 0;
        for _ in 0..n {
            acc += toks.next().unwrap();
        }
        let sign = match acc {
            0 => '0',
            0.. => '+',
            _ => '-',
        };
        writeln!(buf, "{}", sign);
    }
    print!("{}", buf);
}
