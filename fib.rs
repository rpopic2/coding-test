fn get_input() -> u32 {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}

fn main() {
    let n = get_input();
    let mut m2 = 0;
    let mut m1 = 1;
    for _ in 2..n {
        let current = m1 + m2;
        m2 = m1;
        m1 = current;
    }
    println!("{}", m1 + m2);
}
