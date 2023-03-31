use std::io::stdin;
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let input: i32 = input.trim().parse().unwrap();

    let mut buf = String::new();
    for i in 0..input {
        if i % 2 == 1 {
            write!(buf, " ").unwrap();
        }
        for _ in 0..input {
            write!(buf, "* ").unwrap();
        }
        writeln!(buf, "").unwrap();
    }
    print!("{}", buf);
}
