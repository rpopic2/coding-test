use std::io;
use io::Write;
fn main(){
    let stadout = io::stdout();
    let mut out = io::BufWriter::new(stadout.lock());
    let mut buf = String::new();
    let s =
        std::io::stdin()
        .read_line(&mut buf).unwrap();
    let i: i32 = buf
        .trim()
        .parse().unwrap();
    for n in (1..i+1).rev(){
        writeln!(out, "{n}").unwrap();
    }
}
