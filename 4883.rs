use std::io::{self, Read};
use std::fmt::Write;
fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_ascii_whitespace().map(str::parse).flatten();
    let n :i32 = tokens.next().unwrap();

    let mut buf = String::new();
    writeln!(buf, "{}", n).unwrap();
    println!("{}", buf);

}
