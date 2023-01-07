use std::io::{stdin, Read};
use std::fmt::Write;
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut tok = input.split_ascii_whitespace().map(str::parse).flatten();
    let mut buf = String::new();
    let _: i32 = tok.next().unwrap();
    let mut vector = Vec::new();
    for i in tok {
        if i == 0 {
            vector.pop();
        }
        else {
            vector.push(i);
        }
    }
    let sum: i32 = vector.into_iter().sum();
    writeln!(&mut buf, "{}", sum).unwrap();
    print!("{}", buf);
}
