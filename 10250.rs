use std::io::{stdin, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_ascii_whitespace().map(str::parse::<i32>).flatten();
    let mut buf = String::new();
    let t = tokens.next().unwrap();
    for _ in 0..t {
        let h = tokens.next().unwrap();
        tokens.next().unwrap();
        let n = tokens.next().unwrap();
        let floor = (n - 1) % h + 1;
        write!(buf, "{floor}").unwrap();
        let room = (n - 1) / h + 1;
        if room < 10 { write!(buf, "0").unwrap(); }
        writeln!(buf, "{room}").unwrap();
    }
    print!("{}", buf);
}
