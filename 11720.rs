use std::io;
fn main() {
    let mut s = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut s).unwrap();

    let mut ns = String::new();
    stdin.read_line(&mut ns).unwrap();
    let v: u32 = ns.trim().chars().map(|x| x.to_digit(10).unwrap()).sum();
    println!("{v}");
}
