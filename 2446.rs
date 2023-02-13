use std::fmt::Write;
use std::io::stdin;

fn main() {
    let mut input = String::new();
    let n = {
        stdin().read_line(&mut input).unwrap();
        input.trim().parse().unwrap()
    };
    let mut buf = String::new();
    let mut wst = |i| writeln!(buf, "{}{}", " ".repeat(n - i), "*".repeat(i * 2 - 1)).unwrap();
    for i in (1usize..=n).rev() {
        wst(i);
    }
    for i in 2..=n {
        wst(i);
    }
    print!("{}", buf);
}

