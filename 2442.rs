use std::io::stdin;
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse().unwrap();
    let mut buf = String::new();
    let max_star = n + n - 1;
    for i in 1..=n {
        let star_cnt = i + i - 1;
        let margin = (max_star - star_cnt) / 2;
        let line = " ".repeat(margin);
        let sline = "*".repeat(star_cnt);
        writeln!(buf, "{}{}", line, sline).unwrap();
    }
    print!("{}", buf);
}
