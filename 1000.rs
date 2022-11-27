use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();

    let a: i32 = s.split(' ')
        .map(|x| parse_num(x))
        .sum();
    println!("{a}");
}

fn parse_num(s: &str) -> i32 {
    s.trim().parse().expect("nan parse failed")
}
