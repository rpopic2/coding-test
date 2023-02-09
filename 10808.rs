use std::io::stdin;
use std::fmt::Write;

fn main() {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    let mut alphabets = [0; 26];
    for c in line.chars() {
        if c.is_ascii_alphabetic() {
            alphabets[c.to_ascii_lowercase() as usize - 'a' as usize] += 1;
        }
    }
    let mut result = String::new();
    for c in alphabets.iter() {
        write!(&mut result, "{} ", c).unwrap();
    }
    println!("{}", result);
}
