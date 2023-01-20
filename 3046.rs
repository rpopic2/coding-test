use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mut tok = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    //swap flatten into flatten_map!
    let r1 = tok.next().unwrap();
    let s = tok.next().unwrap();
    println!("{}", 2 * s - r1);
}
