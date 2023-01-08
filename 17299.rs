use std::io::{stdin, Read};
use std::fmt::Write;
fn main() {
    let mut buf = String::new();
    let mut input = String::new();
    let n;
    let tok: Vec<i32> = {
        stdin().read_to_string(&mut input).unwrap();
        let mut tmp = input.split_ascii_whitespace().map(str::parse::<i32>).flatten();
        n = tmp.next().unwrap() as usize;
        tmp.collect()
    };
    let cnts = {
        let mut tmp: [usize; 100_001] = [0; 100_001];
        for i in tok.iter() {
            tmp[*i as usize] += 1;
        }
        tmp
    };

    for i in 0..n {
        let cur = tok[i] as usize;
        let ccnt = cnts[cur];
        let mut nfg: i32 = -1;
        for j in (i..n).rev() {
            let nextto = tok[j] as usize;
            let comp = cnts[nextto];
            if comp > ccnt {nfg = nextto as i32};
        }
        writeln!(&mut buf, "{}", nfg).unwrap();
    }
    
    print!("{}", buf);
}
