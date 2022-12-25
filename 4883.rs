use std::cmp::min;
use std::io::{self, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_ascii_whitespace().map(str::parse).flatten();
    let mut buf = String::new();

    let mut test_no = 1;
    loop {
        let rowc:i32 = tokens.next().unwrap();
        if rowc == 0 { break; }
        let mut m :Vec<Vec<i32>> = vec![vec![0; 3]; 2];
        m[0][0] = tokens.next().unwrap();
        m[0][0] = 1 << 16;
        m[0][1] = tokens.next().unwrap();
        m[0][2] = m[0][1] + tokens.next().unwrap();

        for i in 1..rowc as usize {
            let cur_row :usize = i % 2;
            let other_row :usize = (i - 1) % 2;
            m[cur_row][0] = min(m[other_row][0], m[other_row][1]) + tokens.next().unwrap();
            m[cur_row][1] = min(min(m[other_row][0], m[other_row][1]),
                min(m[other_row][2], m[cur_row][0]))
                + tokens.next().unwrap();
            m[cur_row][2] = min(min(m[other_row][1], m[other_row][2]), m[cur_row][1])
                + tokens.next().unwrap();
        }

        writeln!(buf, "{}. {}",test_no, m[(rowc as usize - 1) % 2][1]).unwrap();
        test_no += 1;
    }


    println!("{}", buf);

}
