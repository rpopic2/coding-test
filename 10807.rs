use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let n = input.next().unwrap();
    let query = input.next_back().unwrap();
    let mut counter = 0;

    loop {
        let i = input.next();
        match i {
            None => break,
            Some(i) => {
                if i == query {
                    counter += 1
                }
            }
        }
    }

    println!("{}", counter);
}
