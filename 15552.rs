#![feature(alloc_system)]
extern crate alloc_system;

use std::fmt::Write;
use std::io::{stdin, Read};
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).unwrap();
    let mut iter = s.split_ascii_whitespace().map(|x|x.parse::<i32>()).flatten();
    let mut buf = String::new();
    let t = iter.next().unwrap();
    for _ in 0..t{
       let a = iter.next().unwrap();
       let b = iter.next().unwrap();
       writeln!(buf, "{}", a + b).unwrap();
    }
    println!("{buf}");
}
