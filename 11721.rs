use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let chars = input.chars().enumerate();
    let mut buf = String::new();
    for (i, c) in chars {
        buf.push(c);
        if i % 10 == 9 {
            buf.push('\n');
        }
    }
    println!("{}", buf);
}
