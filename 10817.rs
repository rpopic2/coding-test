use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input);
    let mut toks: Vec<i32>= input.split_ascii_whitespace().flat_map(str::parse::<i32>).collect();
    toks.sort();
    println!("{}", toks[1]);
}
