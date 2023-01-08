use std::io::{stdin, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut buf = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut tok = input.split_ascii_whitespace().map(str::parse).flatten();
    let _: i32 = tok.next().unwrap();
    let pillars: Vec<(i32, i32)> = {
        let mut tmp: Vec<(i32, i32)> = vec![];
        loop {
            let (i, j) = (tok.next(), tok.next());
            if i.is_some() && j.is_some() {
                tmp.push((i.unwrap(), j.unwrap()));
            } else {break;}
        }
        tmp.sort();
        tmp
    };
    let max = pillars.iter().max_by(|x, y|x.1.cmp(&y.1)).unwrap();
    writeln!(&mut buf, "{:?}", max).unwrap();
    for i in pillars {
        writeln!(&mut buf, "{}, {}", i.0, i.1).unwrap();
    }
    print!("{}", buf);
}
