use std::io::stdin;

fn main() {
    let mut rbuf = String::new();
    let input = {
        stdin().read_line(&mut rbuf).unwrap();
        rbuf.strip_suffix('\n').unwrap()
    };
    let mut nums: Vec<char> = input.chars().collect();
    nums.sort_by(|a, b|b.cmp(&a));
    let s = nums.iter().collect::<String>();
    println!("{}", s);
}
