use std::io::{stdin, Read};
use std::fmt::Write;
fn main() {
    let mut buf = String::new();
    let mut input = String::new();
    let n;
    stdin().read_to_string(&mut input).unwrap();
    let mut tmp = input.split_ascii_whitespace().map(str::parse::<usize>).flatten();
    n = tmp.next().unwrap();
    let tok: Vec<usize> = tmp.collect();
    let mut tmp: [usize; 100_001] = [0; 100_001];
    let f = {
        for i in tok.iter() {
            tmp[*i] += 1;
        }
        tmp
    };

    for i in 0..n {
        let cur = tok[i];
        let ccnt = f[cur];
        let mut nfg: usize = 0;
        for j in i..n {
            let nextto = tok[j];
            let comp = f[nextto];
            if comp > ccnt
            {
                nfg = nextto;
                break;
            }
        }
        write!(&mut buf, "{} ", if nfg == 0 {"-1"} else {nfg}).unwrap();
    }
    println!("{}", buf);
}
