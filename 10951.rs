use std::io::{stdin, Read};
use std::fmt::Write;
fn main(){
    let mut s = String::new();
    stdin().read_to_string(&mut s).unwrap();

    let v = s.split_ascii_whitespace().map(|i| i.parse::<u8>().unwrap()).into_iter();

    let mut buf = String::new();
    for i in v{
        let j = v.next().unwrap();
        writeln!(&mut buf, "{}", i + j);
        println!("{i}");
    }
}
