use std::io::stdin;
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse().unwrap();

    let mut buf = String::new();
    for i in (1..=n).chain((1..n).rev()) {
        let ws = " ".repeat((n - i) * 2);
        let star = "*".repeat(i);
        writeln!(buf, "{}{}{}", star, ws, star).unwrap();
    }
    print!("{}", buf);
}
